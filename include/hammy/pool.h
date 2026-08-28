#ifndef HAMMY_POOL_H
#define HAMMY_POOL_H

#include <hammy/job.h>
#include <hammy/worker.h>
#include <pthread.h>
#include <stdint.h>

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t notEmpty;
    hammy_job_t** jobs; // ring buffer
    size_t head;
    size_t tail;
    size_t count;
    size_t cap;
    bool shutdown;

    hammy_worker_t* workers;
    size_t nWorkers;
} hammy_pool_t;

#endif
