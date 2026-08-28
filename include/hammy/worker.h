#ifndef HAMMY_WORKER_H
#define HAMMY_WORKER_H

#include <concord/discord.h>
#include <hammy/types.h>
#include <pthread.h>

struct hammy_worker_t {
    pthread_t thread;
    struct discord* clientCopy; // Clone of the client for concord threading safety
    hammy_pool_t* pool;
    int id;
};

#endif
