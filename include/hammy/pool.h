#ifndef HAMMY_POOL_H
#define HAMMY_POOL_H

#include <concord/discord.h>

#include <pthread.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <hammy/types.h>

// TODO: Change this accordingly; also probably make it configurable without rebuilding at some point
#define HAMMY_POOL_DEFAULT_WORKERS 2
#define HAMMY_POOL_DEFAULT_CAPACITY 64

// Technically, discord allows 15 minutes... but hell no. 30 seconds.
#define HAMMY_JOB_MAX_AGE_MS 30000

typedef enum {
    HAMMY_PUSH_OK = 0, // Queued. Ownership transferred to the pool.
    HAMMY_PUSH_FULL = 1, // At capacity. Caller still owns the job.
    HAMMY_PUSH_SHUTDOWN = 2 // Pool is closing. Caller still owns the job.
} hammy_push_result_t;

struct hammy_pool_t {
    pthread_mutex_t lock;
    pthread_cond_t notEmpty;

    hammy_job_t** jobs; // Ring buffer of cap job pointers - owning while queued
    size_t head; // Next slot to pop
    size_t tail; // Next slot to push
    size_t count; // Live entries - tracked so full != empty ambiguity doesn't exist
    size_t cap;

    size_t busy; // Workers currently processing jobs.
    bool shutdown;

    hammy_worker_t* workers;
    size_t nWorkers;
};

// Creates the pool and starts n_workers threads, each with its own
// discord_clone() of client. Pass 0 for either size to take the defaults.
// Returns NULL on failure; no threads are left running in that case.
// MUST be called from inside a gateway dispatch callback (on_ready is the
// earliest one): discord_clone() copies the gateway's current payload and
// fails with CCORD_ERRNO when there isn't one.
hammy_pool_t* hammy_pool_create(struct discord* client, size_t nWorkers, size_t queueCap);
 
// Enqueues a job. See hammy_push_result_t for who owns the job afterwards.
// Never blocks on anything but the (uncontended, short) queue mutex, so it is
// safe to call from the gateway thread.
hammy_push_result_t hammy_pool_push(hammy_pool_t* pool, hammy_job_t* job);
 
// Signals all workers to finish the queue and exit, then joins them.
// Idempotent. Queued jobs are still run, so an in-flight command still gets a
// reply; use hammy_pool_shutdown_now() if you would rather drop them.
void hammy_pool_shutdown(hammy_pool_t* pool);
 
// As above but discards anything still queued (each dropped job gets an
// apology reply). Call from the gateway thread only - the apologies are
// serialised through the original client, which that thread owns.
void hammy_pool_shutdown_now(hammy_pool_t* pool);
 
// Frees the pool. Runs hammy_pool_shutdown() first if it has not happened yet.
// NULLs the passing reference.
bool hammy_pool_destroy(hammy_pool_t** pool);
 
// Snapshot of queue depth and busy workers, for a /stats command or logging.
void hammy_pool_stats(hammy_pool_t* pool, size_t* outQueued, size_t* outBusy);

#endif
