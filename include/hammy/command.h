#ifndef HAMMY_COMMAND_H
#define HAMMY_COMMAND_H

#include <concord/discord.h>
#include <concord/log.h>
#include <stdbool.h>

#include <hammy/types.h>

// A command handler. Runs either on the gateway thread (instant commands) or on
// a worker thread (deferred ones), so it must not assume either. client is
// whichever client is correct for the calling thread; use it and nothing else.
//
// Instant handlers send a fresh interaction response.
// Deferred handlers EDIT the already-deferred response, via hammy_job_reply()
// or discord_edit_original_interaction_response().
//
// The handler does NOT own the job and must not destroy it.
typedef void (*hammy_command_fn)(const hammy_job_t* job, struct discord* client);
 
// Plain old data. Every field points at static storage, so this struct owns
// nothing, copies freely, and needs no destructor - the vector can be created
// with a NULL destructor hook.
struct hammy_command_t {
    const char* name; // Discord command name. Not owning; expected to be a literal.
    const char* description; // Not owning.
 
    // Registration options, or NULL for none. Not owning; point at a static
    // struct discord_application_command_options, e.g.
    //
    //   static struct discord_application_command_option grid_opt_array[] = {
    //       { .type = DISCORD_APPLICATION_OPTION_STRING, .name = "locator",
    //         .description = "Maidenhead grid", .required = true },
    //   };
    //   static struct discord_application_command_options grid_opts = {
    //       .size = 1, .array = grid_opt_array
    //   };
    struct discord_application_command_options* options;
 
    hammy_command_fn handler;
 
    // true  -> pure computation; answered inline on the gateway thread, no
    //          defer, no queue. Must complete in microseconds.
    // false -> may block (HTTP, DB, file IO); deferred and queued to a worker.
    //
    // Marking a blocking command instant stalls the gateway and risks missed
    // heartbeats. When unsure, leave it false.
    bool instant;
};
 
// The built-in command table. Returns a pointer to static storage; outCount
// receives the number of entries. Never NULL.
const hammy_command_t* hammy_command_builtins(size_t* outCount);
 
// Linear lookup by name over a plain array. The table is small enough that
// anything cleverer is not worth the code.
// Returns NULL if not found.
const hammy_command_t* hammy_command_find(const hammy_command_t* commands, size_t count,
                                          const char* name);
 
// True if the command is safe to run inline on the gateway thread.
// Tolerates NULL so callers can skip a null check.
bool hammy_command_is_instant(const hammy_command_t* command);

#endif
