#ifndef HAMMY_POOL_H
#define HAMMY_POOL_H

#include <hammy/types.h>
#include <pthread.h>
#include <stdint.h>

struct hammy_pool_t {
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
};

#endif
