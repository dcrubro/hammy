#include <concord/discord.h>
#include <concord/log.h>
#include <stdlib.h>

#include <hammy/job.h>
#include <hammy/pool.h>
#include <hammy/worker.h>

hammy_pool_t* hammy_pool_create(struct discord* client, size_t nWorkers, size_t queueCap) {
    if (!client) { return NULL; }

    if (nWorkers == 0) { nWorkers = HAMMY_POOL_DEFAULT_WORKERS; }
    if (queueCap == 0) { queueCap = HAMMY_POOL_DEFAULT_CAPACITY; }

    hammy_pool_t* pool = (hammy_pool_t*)calloc(1, sizeof(*pool));
    if (!pool) { return NULL; }

    pool->cap = queueCap;
    pool->jobs = (hammy_job_t**)calloc(pool->cap, sizeof(*pool->jobs));
    if (!pool->jobs) {
        goto fail_jobs;
    }

    pool->workers = (hammy_worker_t*)calloc(nWorkers, sizeof(*pool->workers));
    if (!pool->workers) {
        goto fail_workers;
    }

    if (pthread_mutex_init(&pool->lock, NULL) != 0) {
        goto fail_mutex;
    }

    if (pthread_cond_init(&pool->notEmpty, NULL) != 0) {
        goto fail_cond;
    }

    // nWorkers counts STARTED threads, so a partial failure below still joins
    // exactly the ones that exist.
    for (size_t i = 0; i < nWorkers; i++) {
        if (!hammy_worker_start(&pool->workers[i], pool, client, (int)i)) {
            log_error("[pool] only %zu of %zu workers started, bailing!", i, nWorkers);
            hammy_pool_shutdown(pool);
            hammy_pool_destroy(&pool);

            return NULL;
        }

        pool->nWorkers++;
    }

    log_info("[pool] Started %zu workers, queue cap %zu", pool->nWorkers, pool->cap);

    return pool;

// GOTOs
fail_cond:
    pthread_mutex_destroy(&pool->lock);
fail_mutex:
    free(pool->workers);
fail_workers:
    free(pool->jobs);
fail_jobs:
    free(pool);

    return NULL;

}

hammy_push_result_t hammy_pool_push(hammy_pool_t* pool, hammy_job_t* job) {
    if (!pool || !job) { return HAMMY_PUSH_SHUTDOWN; }

    pthread_mutex_lock(&pool->lock);

    if (pool->shutdown) {
        pthread_mutex_unlock(&pool->lock);
        return HAMMY_PUSH_SHUTDOWN;
    }

    if (pool->count == pool->cap) {
        pthread_mutex_unlock(&pool->lock);
        return HAMMY_PUSH_FULL;
    }

    pool->jobs[pool->tail] = job;
    pool->tail = (pool->tail + 1) % pool->cap;
    pool->count++;

    // Signal inside the lock, wakeup cost kinda irrlevant compared to HTTP round trips
    pthread_cond_signal(&pool->notEmpty);
    pthread_mutex_unlock(&pool->lock);

    return HAMMY_PUSH_OK;
}

static void hammy_pool_stop(hammy_pool_t* pool, bool drain) {
    if (!pool) { return; }

    pthread_mutex_lock(&pool->lock);

    if (pool->shutdown) {
        pthread_mutex_unlock(&pool->lock);
        return;
    }

    pool->shutdown = true;

    if (!drain) {
        while (pool->count > 0) {
            hammy_job_t* job = pool->jobs[pool->head];
            pool->head = (pool->head + 1) % pool->cap;
            pool->count--;

            hammy_job_destroy(&job);
        }
    }

    // Broadcast (NOT signal), every watier has to see the shutdown flag and exit, not just one.
    pthread_cond_broadcast(&pool->notEmpty);
    pthread_mutex_unlock(&pool->lock);

    for (size_t i = 0; i < pool->nWorkers; i++) {
        hammy_worker_join(&pool->workers[i]);
    }

    log_info("[pool] Shut down");
}

void hammy_pool_shutdown(hammy_pool_t* pool) {
    hammy_pool_stop(pool, true);
}
 
void hammy_pool_shutdown_now(hammy_pool_t* pool) {
    hammy_pool_stop(pool, false);
}

bool hammy_pool_destroy(hammy_pool_t** pool) {
    if (!pool || !*pool) { return false; }

    hammy_pool_t* p = *pool;

    hammy_pool_shutdown(p); // No-op if already shut down

    // Anything still queued after the drain is a but - free rather than leak it.
    while (p->count > 0) {
        hammy_job_t* job = p->jobs[p->head];
        p->head = (p->head + 1) % p->cap;
        p->count--;

        hammy_job_destroy(&job);
    }

    pthread_cond_destroy(&p->notEmpty);
    pthread_mutex_destroy(&p->lock);

    free(p->workers);
    free(p->jobs);
    free(p);

    *pool = NULL;

    return true;
}

void hammy_pool_stats(hammy_pool_t* pool, size_t* outQueued, size_t* outBusy) {
    if (!pool) { return; }

    pthread_mutex_lock(&pool->lock);
    if (outBusy) { *outBusy = pool->busy; }
    if (outQueued) { *outQueued = pool->count; }
    pthread_mutex_unlock(&pool->lock);
}