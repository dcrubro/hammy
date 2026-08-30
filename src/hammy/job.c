#include <concord/discord.h>
#include <concord/log.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include <hammy/bot.h>
#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/embeds.h>

// strdup() is POSIX, so we'll keep a local and keep the code portable.
static char* hammy_strdup(const char* src) {
    if (!src) { return NULL; }

    size_t len = strlen(src) + 1; // +1 for the null terminator
    char* dst = (char*)malloc(len);
    if (!dst) { return NULL; }

    memcpy(dst, src, len);

    return dst;
}

// Logs a failed send, and only a failed send. Concord returns CCORD_PENDING for
// an asynchronous request (which is every request made with a NULL ret, i.e.
// all of ours) - the request has been queued, not rejected, so treating it as
// an error warned on every single reply that actually worked.
static void hammy_job_check_send(const hammy_job_t* job, CCORDcode code) {
    if (code == CCORD_OK || code == CCORD_PENDING) { return; }

    log_warn("[job] Failed to send interaction response for interaction %" PRIu64 ": %s (%d)",
             job->id, ccord_strerror(code), code);
}

// Pulls the invoking user out of the event. Guild interactions carry it under
// member->user, DM interactions under user directly.
static u64snowflake hammy_job_extract_user(const struct discord_interaction* event) {
    if (event->member && event->member->user) return event->member->user->id;
    if (event->user) return event->user->id;
 
    return 0;
}

hammy_job_t* hammy_job_create(hammy_bot_t* bot, const struct discord_interaction* event) {
    if (!bot || !bot->client || !event) { return NULL; }

    hammy_job_t* job = (hammy_job_t*)calloc(1, sizeof(*job));
    if (!job) { return NULL; }

    job->bot = bot;
    job->id = event->id;
    job->user = hammy_job_extract_user(event);
    job->token = hammy_strdup(event->token);
    job->queuedAt = (int64_t)discord_timestamp(bot->client);

    job->appId = event->application_id ? event->application_id : bot->appId;

    if (!job->token) {
        goto fail;
    }

    if (event->data && event->data->name) {
        job->command = hammy_strdup(event->data->name);
        if (!job->command) {
            goto fail;
        }
    }

    // Flatten the top-level options. Subcommand groups nest another options array inside an option
    // Not handled yet, and worth revisiting before we need one; TODO
    if (event->data && event->data->options && event->data->options->size > 0) {
        size_t n = (size_t)event->data->options->size;

        job->args = (hammy_arg_t*)calloc(n, sizeof(*job->args));
        if (!job->args) {
            goto fail;
        }

        for (size_t i = 0; i < n; i++) {
            struct discord_application_command_interaction_data_option* opt = &event->data->options->array[i];

            job->args[i].name = hammy_strdup(opt->name);
            job->args[i].value = hammy_strdup(opt->value);

            // A NULL value is legitimate for a flag-style option; a NULL name
            // after a non-NULL source is an allocation failure.
            if (opt->name && !job->args[i].name) goto fail;
            if (opt->value && !job->args[i].value) goto fail;
 
            job->nArgs++;
        }
    }

    return job;

fail:
    hammy_job_destroy(&job);
    return NULL;
}

bool hammy_job_destroy(hammy_job_t** job) {
    if (!job || !*job) { return false; }

    hammy_job_t* j = *job;

    for (size_t i = 0; i < j->nArgs; i++) {
        free(j->args[i].name);
        free(j->args[i].value);
    }

    free(j->args);
    free(j->token);
    free(j->command);
    free(j);

    *job = NULL;

    return true;
}

const char* hammy_job_get_arg(const hammy_job_t* job, const char* name) {
    if (!job || !name) { return NULL; }

    for (size_t i = 0; i < job->nArgs; i++) {
        if (job->args[i].name && strcmp(job->args[i].name, name) == 0) {
            return job->args[i].value;
        }
    }

    return NULL;
}

int64_t hammy_job_age_ms(const hammy_job_t* job, struct discord* client) {
    if (!job || !client) { return 0; }

    return (int64_t)discord_timestamp(client) - job->queuedAt;
}

void hammy_job_reply(const hammy_job_t* job, struct discord* client, const char* title, const char* content, bool isError) {
    if (!job || !client || !content || !title) { return; }

    // Editing, not creating: every caller is on the deferred path, where the
    // gateway thread already sent DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE. A second
    // create on the same interaction is refused with "Interaction has already
    // been acknowledged" (40060). Instant handlers want hammy_job_respond().
    struct discord_edit_original_interaction_response params = { 0 };

    // Both must outlive the call, so neither can be a compound literal inside
    // the branch below.
    struct discord_embed embed[1];
    struct discord_embeds embeds = { .size = 1, .array = embed };

    if (hammy_embeds_customembed(client, embed, NULL, title, content, NULL, 0, isError ? 0xFF0000 : 0x00FF00)) {
        params.embeds = &embeds;
    } else {
        // Only reachable on a bad argument, but a plain-text body still beats
        // sending nothing at all.
        params.content = (char*)content;
    }

    hammy_job_check_send(job, discord_edit_original_interaction_response(client, job->appId, job->token, &params, NULL));
}

void hammy_job_respond(const hammy_job_t* job, struct discord* client, const char* title, const char* content, bool isError) {
    if (!job || !client || !content || !title) { return; }

    struct discord_embed embed[1];
    if (hammy_embeds_customembed(client, embed, NULL, title, content, NULL, 0, isError ? 0xFF0000 : 0x00FF00)) {
        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data){
                .embeds = &(struct discord_embeds){
                    .size = 1,
                    .array = embed
                }
            }
        };

        hammy_job_check_send(job, discord_create_interaction_response(client, job->id, job->token, &params, NULL));
    } else {
        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
            .data = &(struct discord_interaction_callback_data){
                .content = (char*)content
            }
        };

        hammy_job_check_send(job, discord_create_interaction_response(client, job->id, job->token, &params, NULL));
    }
}

void hammy_job_run(hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    if (!job || !client) { return; }
    if (!refdb) {
        // TODO: Consider making this a hard-fail
        log_warn("[job] Ran command '%s' for interaction %" PRIu64 " without a valid refdb! SQLite functions will be unavailable!", job->command ? job->command : "unknown", job->id);
    }

    log_info("[job] Running command '%s' for interaction %" PRIu64, job->command ? job->command : "unknown", job->id);
    const hammy_command_t* command = hammy_bot_find_command(job->bot, job->command);
    if (!command || !command->handler) {
        log_warn("[job] No handler found for command '%s'.", job->command ? job->command : "unknown");
        hammy_job_reply(job, client, "Unknown Command", "I don't know that command!", true);
        return;
    }

    command->handler(job, client, refdb);
}
