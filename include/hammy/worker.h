#ifndef HAMMY_WORKER_H
#define HAMMY_WORKER_H

#include <concord/discord.h>
#include <hammy/types.h>
#include <pthread.h>

struct hammy_worker_t {
    pthread_t thread;
    struct discord* clientCopy; // Clone of the client for concord threading safety - owning
    hammy_pool_t* pool; // Non-owning back-reference
    int id; // Log logging mainly
    bool started; // For joining
};

// Clones client, spawns the thread. Returns false on clone or spawn failure,
// leaving the worker safe to pass to hammy_worker_join().
// Inherits hammy_pool_create()'s precondition: the clone only succeeds from
// inside a gateway dispatch callback.
bool hammy_worker_start(hammy_worker_t* worker, hammy_pool_t* pool, struct discord* client, int id);
 
// Joins the thread if it was started and cleans up the clone.
// The caller must have already set pool->shutdown and broadcast, or this hangs.
void hammy_worker_join(hammy_worker_t* worker);

#endif
