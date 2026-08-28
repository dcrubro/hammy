#include <concord/discord.h>
#include <concord/log.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include <hammy/job.h>

// strdup() is POSIX, so we'll keep a local and keep the code portable.
static char* hammy_strdup(const char* src) {
    if (!src) { return NULL; }

    size_t len = strlen(src) + 1; // +1 for the null terminator
    char* dst = (char*)malloc(len);
    if (!dst) { return NULL; }

    memcpy(dst, src, len);

    return dst;
}

// Pulls the invoking user out of the event. Guild interactions carry it under
// member->user, DM interactions under user directly.
static u64snowflake hammy_job_extract_user(const struct discord_interaction* event) {
    if (event->member && event->member->user) return event->member->user->id;
    if (event->user) return event->user->id;
 
    return 0;
}

hammy_job_t* hammy_job_create(struct discord* client, const struct discord_interaction* event) {
    if (!client || !event) { return NULL; }

    hammy_job_t* job = (hammy_job_t*)calloc(1, sizeof(*job));
    if (!job) { return NULL; }

    job->id = event->id;
    job->appId = event->application_id;
    job->user = hammy_job_extract_user(event);
    job->token = hammy_strdup(event->token);
    job->queuedAt = (int64_t)discord_timestamp(client);

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

void hammy_job_reply(const hammy_job_t* job, struct discord* client, const char* content) {
    if (!job || !client || !content) { return; }

    // TODO: Embeds
    struct discord_edit_original_interaction_response params = {
        .content = (char*)content
    };

    CCORDcode code = discord_edit_original_interaction_response(client, job->appId, job->token, &params, NULL);
    if (code != CCORD_OK) {
        log_warn("[job] Failed to edit response for interaction %" PRIu64 ": %d", job->id, code);
    }
}

void hammy_job_run(hammy_job_t* job, struct discord* client) {
    if (!job || !client) { return; }

    // TODO: look job->command up in the bot's command vector and call its
    // handler with (job, client). Placeholder until command.h grows a
    // dispatch entry point.
    log_info("[job] Running command '%s' for interaction %" PRIu64, job->command ? job->command : "unknown", job->id);

    hammy_job_reply(job, client, "This is a placeholder reply. The command handler is not yet implemented.");
}
