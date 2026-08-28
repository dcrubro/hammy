#ifndef HAMMY_BOT_H
#define HAMMY_BOT_H

#include <concord/discord.h>
#include <dlibc/vector.h>
#include <stdlib.h>

#include <hammy/types.h>
#include <hammy/command.h>

struct hammy_bot_t {
    struct discord* client; // Owning reference to the client - handoff from main.c
    bool commands_registered; // A flag if commands have been registered. Avoid re-registering every reconnect.
    vector_t* commands; // vector_t of commands. Owning.
};

// Alloc on heap and create
hammy_bot_t* hammy_bot_create();

// Sets the on_ready() call function pointer
bool hammy_bot_set_on_ready(hammy_bot_t* bot, void (*func)(struct discord* client, const struct discord_ready* event));

// Runs the bot. Return true on succeed, false on failure.
bool hammy_bot_run(hammy_bot_t* bot);

// Adds a command to the vector as a COPY, get rid of the old struct.
bool hammy_bot_add_command(hammy_bot_t* bot, hammy_command_t* command);

// Registers all commands. Return true if succeeded or already registered; false if failure.
bool hammy_bot_register_commands(hammy_bot_t* bot);

// Destroy bot, NULLs the passing reference
bool hammy_bot_destroy(hammy_bot_t** bot);

#endif
