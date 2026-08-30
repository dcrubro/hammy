#include <concord/discord.h>
#include <concord/log.h>
#include <dlibc/vector.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
 
#include <hammy/bot.h>
#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/pool.h>
#include <hammy/embeds.h>

static void hammy_bot_attach(struct discord* client, hammy_bot_t* bot) {
    discord_set_data(client, bot);
}

static hammy_bot_t* hammy_bot_from_client(struct discord* client) {
    return (hammy_bot_t*)discord_get_data(client);
}

static void hammy_bot_on_interaction(struct discord* client, const struct discord_interaction* event) {
    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND) {
        return;
    }

    hammy_bot_t* bot = hammy_bot_from_client(client);
    if (!bot) {
        log_warn("[bot] No bot data attached to client. Cannot handle interaction.");
        return;
    }

    const char* name = (event->data && event->data->name) ? event->data->name : NULL;
    const hammy_command_t* command = hammy_bot_find_command(bot, name);
    if (!command) {
        log_warn("[bot] No command found for interaction '%s'.", name ? name : "(null)");
        
        struct discord_interaction_response params = {
            .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        };

        struct discord_embed embed[1];
        CCORDcode code;
        if (hammy_embeds_customerror(client, embed, NULL, "Unknown Command", "I don't know that command!", NULL, 0)) {
            params.data = &(struct discord_interaction_callback_data){
                .embeds = &(struct discord_embeds){
                    .size = 1,
                    .array = embed
                }
            };
            
            code = discord_create_interaction_response(client, event->id, event->token, &params, NULL);
        } else {
            params.data = &(struct discord_interaction_callback_data){
                .content = "I don't know that command!"
            };

            code = discord_create_interaction_response(client, event->id, event->token, &params, NULL);
        }

        if (code != CCORD_OK) {
            log_warn("[job] Failed to send interaction error response for interaction %" PRIu64 ": %d", event->id, code);
        }

        return;
    }

    hammy_job_t* job = hammy_job_create(bot, event);
    if (!job) {
        log_error("[bot] Failed to create job for interaction '%s'.", name ? name : "(null)");
        return;
    }

    // Instant path: no defer or queue, answered on the spot
    if (command->instant) {
        command->handler(job, client, bot->refdb);
        hammy_job_destroy(&job);
        return;
    }

    // Deferred path: ACK first, 3 second window by discord, then queue to worker pool
    struct discord_interaction_response deferred = {
        .type = DISCORD_INTERACTION_DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE,
    };

    discord_create_interaction_response(client, event->id, event->token, &deferred, NULL);

    switch (hammy_pool_push(bot->pool, job)) {
        case HAMMY_PUSH_OK:
            log_info("[bot] Queued job for interaction '%s'.", name ? name : "(null)");
            break;
        case HAMMY_PUSH_FULL:
            log_warn("[bot] Queue pool full. Cannot queue job for interaction '%s'.", name ? name : "(null)");
            hammy_job_reply(job, client, "Bot is Busy", "I am a bit busy right now! Please try again later.", true);
            hammy_job_destroy(&job);
            break;
        case HAMMY_PUSH_SHUTDOWN:
            // Also covers the window before on_ready starts the pool, since
            // hammy_pool_push() reports a NULL pool the same way.
            log_error("[bot] Worker pool unavailable. Cannot queue job for interaction '%s'.", name ? name : "(null)");
            hammy_job_reply(job, client, "Bot is Offline", "Hammy is not accepting commands right now. Please try again shortly.", true);
            hammy_job_destroy(&job);
            break;
    }
}

hammy_bot_t* hammy_bot_create() {
    hammy_bot_t* bot = (hammy_bot_t*)calloc(1, sizeof(*bot));
    if (!bot) {
        return NULL;
    }

    // Set defaults
    bot->client = NULL;
    bot->commandsRegistered = false;
    bot->commands = vector_create(sizeof(hammy_command_t));

    // Check if vector allocation errored
    if (!bot->commands) {
        free(bot);
        return NULL;
    }

    // Open a reference to sqlite
    bot->refdb = hammy_refdb_open("hammy-ref.sqlite"); // TODO: Probably don't hardcode this?
    if (!bot->refdb) {
        log_error("[bot] Failed to open ref to sqlite. Commands requiring it will be unavailable!"); // TODO: Consider making this a hard-fail
    }

    return bot;
}

bool hammy_bot_add_command(hammy_bot_t* bot, const hammy_command_t* command) {
    if (!bot || !bot->commands || !command || !command->name) { return false; }

    // Copy the command into the vector. The command owns nothing, so this is safe.
    if (vector_push_back(bot->commands, command) < 0) {
        log_error("[bot] Failed to add command '%s' to bot.", command->name);
        return false;
    }

    log_info("[bot] Loaded command '%s'.", command->name);
    
    return true;
}

bool hammy_bot_load_builtins(hammy_bot_t* bot) {
    if (!bot) { return false; }

    size_t count = 0;
    const hammy_command_t* builtins = hammy_command_builtins(&count);

    for (size_t i = 0; i < count; i++) {
        if (!hammy_bot_add_command(bot, &builtins[i])) {
            log_error("[bot] Failed to load builtin command '%s'.", builtins[i].name);
            return false;
        }
    }

    log_info("[bot] Loaded %zu builtin commands.", count);

    return true;
}

const hammy_command_t* hammy_bot_find_command(const hammy_bot_t* bot, const char* name) {
    if (!bot || !bot->commands || !name) { return NULL; }

    // Vector guarantees contiguous and gapless storage, so a plain-array search is fine.
    const hammy_command_t* commands = (const hammy_command_t*)vector_as_c_array(bot->commands);

    return hammy_command_find(commands, vector_size(bot->commands), name);
}

bool hammy_bot_start_pool(hammy_bot_t* bot, size_t nWorkers, size_t queueCap) {
    if (!bot || !bot->client) { return false; }
    if (bot->pool) {
        // A reconnect re-fires READY, so this is routine rather than a problem.
        log_debug("[bot] Worker pool already started. No-op.");
        return true; // Already started
    }

    bot->pool = hammy_pool_create(bot->client, nWorkers, queueCap);
    
    if (!bot->pool) {
        log_error("[bot] Failed to create worker pool.");
        return false;
    }

    return true;
}

bool hammy_bot_deregister_all_commands(hammy_bot_t* bot) {
    // TODO: This leaks and I don't know why. Figure it out.
    if (!bot || !bot->client) { return false; }

    struct discord_application_commands cmds = {0};
    struct discord_ret_application_commands ret = { .sync = &cmds };

    if (discord_get_global_application_commands(bot->client, bot->appId, &ret) == CCORD_OK) {
        for (int i = 0; i < cmds.size; i++) {
            discord_delete_global_application_command(bot->client, bot->appId, cmds.array[i].id, NULL);
        }
    } else {
        log_error("[bot] Failed to deregister global commands!");
        return false;
    }

    const char* devGuild = getenv("HAMMY_DEV_GUILD");
    u64snowflake guildId = devGuild ? (u64snowflake)strtoull(devGuild, NULL, 10) : 0;

    if (guildId) {
        if (discord_get_guild_application_commands(bot->client, bot->appId, guildId, &ret) == CCORD_OK) {
            for (int i = 0; i < cmds.size; i++) {
                discord_delete_guild_application_command(bot->client, bot->appId, guildId, cmds.array[i].id, NULL);
            }
        } else {
            log_error("[bot] Failed to deregister dev guild commands!");
            return false;
        }
    }

    bot->commandsRegistered = false;

    return true;
}

bool hammy_bot_register_commands(hammy_bot_t* bot) {
    if (!bot || !bot->client) { return false; }
    if (bot->commandsRegistered) { return true; } // Already registered

    if (!bot->appId) {
        log_error("[bot] No application ID set. Cannot register commands. This should be set in the on_ready() callback.");
        return false;
    }

    const char* devGuild = getenv("HAMMY_DEV_GUILD");
    u64snowflake guildId = devGuild ? (u64snowflake)strtoull(devGuild, NULL, 10) : 0;

    size_t count = vector_size(bot->commands);

    for (size_t i = 0; i < count; i++) {
        const hammy_command_t* cmd = (const hammy_command_t*)vector_get_const(bot->commands, i);

        if (!cmd || !cmd->name || !cmd->description) {
            log_warn("[bot] Invalid command at index %zu. Cannot register with Discord. Skipping!", i);
            continue; // Skip this command, but try to register the rest
        }

        CCORDcode code;

        if (guildId) {
            struct discord_create_guild_application_command params = {
                .name = (char*)cmd->name,
                .description = (char*)cmd->description,
                .options = cmd->options
            };

            code = discord_create_guild_application_command(bot->client, bot->appId, guildId, &params, NULL);
        } else {
            struct discord_create_global_application_command params = {
                .name = (char*)cmd->name,
                .description = (char*)cmd->description,
                .options = cmd->options
            };

            code = discord_create_global_application_command(bot->client, bot->appId, &params, NULL);
        }

        // Passing NULL for the return handle makes these fire-and-forget, so
        // a successful enqueue reports CCORD_PENDING rather than CCORD_OK.
        if (code != CCORD_OK && code != CCORD_PENDING) {
            log_error("[bot] Failed to register command '%s' with Discord. Error code: %d", cmd->name, code);
            return false;
        }
    }

    bot->commandsRegistered = true;
    log_info("[bot] Successfully registered %zu commands with Discord %s.", count, guildId ? "to dev guild" : "globally");

    return true;
}

bool hammy_bot_set_on_ready(hammy_bot_t* bot, void (*func)(struct discord* client, const struct discord_ready* event)) {
    if (!bot || !func || !bot->client) { return false; }

    discord_set_on_ready(bot->client, func);

    return true;
}

bool hammy_bot_run(hammy_bot_t* bot) {
    if (!bot || !bot->client) { return false; }

    hammy_bot_attach(bot->client, bot);
    discord_set_on_interaction_create(bot->client, &hammy_bot_on_interaction);

    return discord_run(bot->client) == CCORD_OK;
}

bool hammy_bot_destroy(hammy_bot_t** bot) {
    if (!bot || !(*bot)) { return false; }

    hammy_bot_t* b = *bot;

    // Workers hold clones of the client
    if (b->pool) {
        hammy_pool_destroy(&b->pool);
    }

    // No element destructor, commands own nothing.
    if (b->commands) {
        vector_destroy(&b->commands);
    }

    if (b->client) {
        discord_cleanup(b->client);
        b->client = NULL;
    }

    if (b->refdb) {
        hammy_refdb_close(&b->refdb);
    }

    free(*bot);
    *bot = NULL;

    return true;
}
