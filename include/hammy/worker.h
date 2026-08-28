#ifndef HAMMY_WORKER_H
#define HAMMY_WORKER_H

#include <concord/discord.h>
#include <hammy/job.h>
#include <pthread.h>

typedef struct hammy_pool_t; // forward declare

typedef struct {
    pthread_t thread;
    struct discord* clientCopy; // Clone of the client for concord threading safety
    hammy_pool_t* pool;
    int id;
} hammy_worker_t;

#endif
