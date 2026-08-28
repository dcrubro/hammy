#ifndef HAMMY_JOB_H
#define HAMMY_JOB_H

#include <concord/discord.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <hammy/types.h>

// A single slash-command option. Flattened out of the interaction event.
// Both strings are owned by the job.
typedef struct hammy_arg_t {
    char* name;
    char* value;
} hammy_arg_t;

// A unit of deferred work handed from the gateway thread to a worker.
//
// OWNERSHIP: a job is created by the gateway thread and, on a successful
// hammy_pool_push(), ownership transfers to the pool. After that the creating
// thread MUST NOT touch it again. The worker that pops it owns it and destroys
// it. On a failed push the caller still owns it and must destroy it itself.
struct hammy_job_t {
    char* token; // Interaction token - owning
    u64snowflake id; // Interaction ID
    u64snowflake appId; // Application ID, needed to edit the original response
    u64snowflake user; // Invoking User ID, rate limiting, logging, etc.
    char* command; // Command name - owning
    hammy_arg_t* args; // Array of size nArgs. Owning, array and contents.
    size_t nArgs;
    int64_t queuedAt; // Staleness checks, in ms. From discord_timestamp().
};

// Deep-copies everything the job needs out of the interaction event, so the
// event may be freed by Concord the moment the handler returns.
// Returns NULL on allocation failure.
hammy_job_t* hammy_job_create(struct discord* client, const struct discord_interaction* event);
 
// Frees the job and everything it owns. NULLs the passing reference.
// Safe to call with NULL or with a pointer to NULL.
bool hammy_job_destroy(hammy_job_t** job);
 
// Looks up an option by name. Returns NULL if absent. Result is owned by the job.
const char* hammy_job_get_arg(const hammy_job_t* job, const char* name);
 
// Milliseconds elapsed since the job was created.
int64_t hammy_job_age_ms(const hammy_job_t* job, struct discord* client);
 
// Runs the job to completion and sends the reply. Called from a worker thread,
// so client MUST be that worker's own clone, never the gateway client.
// Does not destroy the job.
void hammy_job_run(hammy_job_t* job, struct discord* client);
 
// Edits the (already deferred) interaction response with a plain text body.
// Used by hammy_job_run() and by the pool's error paths.
void hammy_job_reply(const hammy_job_t* job, struct discord* client, const char* content);

#endif
