#include <concord/discord.h>
#include <concord/log.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <hammy/bot.h>
#include <hammy/pool.h>

#define HAMMY_CONFIG_PATH "config.json"

static hammy_bot_t* g_bot = NULL;

static void hammy_on_sigint(int sig) {
    (void)sig;

    // Only sets a flag inside Concord and makes discord_run() return. The real
    // teardown happens back in main().
    if (g_bot && g_bot->client) discord_shutdown(g_bot->client);
}

static void hammy_on_ready(struct discord* client, const struct discord_ready* event) {
    hammy_bot_t* bot = (hammy_bot_t*)discord_get_data(client);
    if (!bot) return;

    log_info("[hammy] logged in as %s", event->user->username);

    // The application id is only available now, and both registration and
    // response editing need it.
    bot->appId = event->application->id;

    //hammy_bot_deregister_all_commands(bot);

    // discord_clone() deep-copies the gateway's *current* payload, so it only
    // succeeds from inside a dispatch callback. READY is the first one we get.
    if (!hammy_bot_start_pool(bot, 0, 0)) { // 0, 0 = defaults
        log_fatal("[hammy] Could not start the worker pool. Shutting down.");
        discord_shutdown(client);

        return;
    }

    hammy_bot_register_commands(bot);
}

int main(void) {
    ccord_global_init();

    hammy_bot_t* bot = hammy_bot_create();
    if (!bot) {
        fprintf(stderr, "could not create bot\n");
        ccord_global_cleanup();

        return EXIT_FAILURE;
    }

    // Token and logging settings both come out of config.json.
    bot->client = discord_config_init(HAMMY_CONFIG_PATH);
    if (!bot->client) {
        fprintf(stderr, "could not init discord client from %s\n", HAMMY_CONFIG_PATH);
        hammy_bot_destroy(&bot);
        ccord_global_cleanup();

        return EXIT_FAILURE;
    }

    bool ok = false; // Declared before the gotos so they don't jump over it.

    g_bot = bot;
    signal(SIGINT, &hammy_on_sigint);
    signal(SIGTERM, &hammy_on_sigint);

    // Order matters: commands loaded before the ready callback can register
    // them. The pool starts from on_ready, not here - see the comment there.
    if (!hammy_bot_load_builtins(bot)) goto fail;
    if (!hammy_bot_set_on_ready(bot, &hammy_on_ready)) goto fail;

    // Blocks until shutdown. A NULL pool afterwards means on_ready bailed out
    // before it could start one.
    ok = hammy_bot_run(bot) && bot->pool != NULL;

    hammy_bot_destroy(&bot);
    ccord_global_cleanup();

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;

fail:
    hammy_bot_destroy(&bot);
    ccord_global_cleanup();

    return EXIT_FAILURE;
}
