#ifndef HAMMY_BOT_H
#define HAMMY_BOT_H

#include <concord/discord.h>
#include <dlibc/vector.h>
#include <stdlib.h>

#include <hammy/types.h>
#include <hammy/command.h>

struct hammy_bot_t {
    struct discord* client; // Owning reference to the client - handoff from main.c
    bool commandsRegistered; // A flag if commands have been registered. Avoid re-registering every reconnect.
    vector_t* commands; // vector_t of commands. Owning the vector, NOT the elements.
    hammy_pool_t* pool; // Owning reference to the thread pool.
    u64snowflake appId; // Learned from the ready event.
};

// Alloc on heap and create
hammy_bot_t* hammy_bot_create();
 
// Sets the on_ready() call function pointer
bool hammy_bot_set_on_ready(hammy_bot_t* bot, void (*func)(struct discord* client, const struct discord_ready* event));
 
// Copies every entry from hammy_command_builtins() into the vector.
bool hammy_bot_load_builtins(hammy_bot_t* bot);
 
// Starts the worker pool. Pass 0 for the defaults. Call this from the ready
// callback, NOT before hammy_bot_run(): the workers are built on
// discord_clone(), which only succeeds inside a gateway dispatch.
// Returns true if the pool is already running.
bool hammy_bot_start_pool(hammy_bot_t* bot, size_t nWorkers, size_t queueCap);
 
// Runs the bot. Return true on succeed, false on failure.
bool hammy_bot_run(hammy_bot_t* bot);
 
// Adds a command to the vector as a COPY. Commands own nothing, so the source
// struct needs no cleanup and may be a compound literal.
bool hammy_bot_add_command(hammy_bot_t* bot, const hammy_command_t* command);
 
// Looks a command up by name. Returns a pointer into the vector's storage, or
// NULL. Valid until the vector is next modified, which after startup is never.
const hammy_command_t* hammy_bot_find_command(const hammy_bot_t* bot, const char* name);

// Wipes all commands from the Discord registry. Return true on success, false on failure.
bool hammy_bot_deregister_all_commands(hammy_bot_t* bot);

// Registers all commands with Discord. Return true if succeeded or already
// registered; false if failure. Requires bot->application_id to be set, so call
// this from on_ready, not before.
bool hammy_bot_register_commands(hammy_bot_t* bot);
 
// Destroy bot, NULLs the passing reference
bool hammy_bot_destroy(hammy_bot_t** bot);

#endif
