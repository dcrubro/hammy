#include <hammy/bot.h>

hammy_bot_t* hammy_bot_create() {
    hammy_bot_t* bot = (hammy_bot_t*)malloc(sizeof(hammy_bot_t));
    if (!bot) {
        return NULL;
    }

    // Set defaults
    bot->client = NULL;
    bot->commands_registered = false;
    bot->commands = vector_create(sizeof(hammy_command_t));

    // Check if vector allocation errored
    if (!bot->commands) {
        free(bot);
        return NULL;
    }

    if (vector_set_destructor(bot->commands, &hammy_command_destroy) < 0) {
        vector_destroy(&bot->commands);
        free(bot);
        return NULL;
    }

    // Init the discord client - even though this is an owning reference, the main() and others may call functions on it (if we don't stay singlethread anymore then FIX THIS)
    bot->client = discord_from_json("config.json");
    if (!bot->client) {
        vector_destroy(&bot->commands);
        free(bot);
        return NULL;
    }

    return bot;
}

bool hammy_bot_set_on_ready(hammy_bot_t* bot, void (*func)(struct discord* client, const struct discord_ready* event)) {
    if (!bot || !func || !bot->client) { return false; }

    discord_set_on_ready(bot->client, func);
    return true;
}

bool hammy_bot_run(hammy_bot_t* bot) {
    if (!bot || !bot->client) { return false; }

    discord_run(bot->client);

    return true;
}

bool hammy_bot_add_command(hammy_bot_t* bot, hammy_command_t* command) {
    if (!bot || !command) { return false; }

    // Push into commands vector
    if (vector_push_back(bot->commands, command) < 0) {
        return false;
    }

    return true;
}

bool hammy_bot_register_commands(hammy_bot_t* bot) {
    if (!bot) { return false; }

    // TODO: Figure out registration logic
}

bool hammy_bot_destroy(hammy_bot_t** bot) {
    if (!bot || !(*bot)) { return false; }

    if ((*bot)->client) {
        discord_cleanup((*bot)->client);
    }

    // TODO: Potential other stuff here
    vector_destroy(&(*bot)->commands); // commands is NULL form hereon, calls destructors on commands automatically
    free(*bot);
    *bot = NULL;
}
