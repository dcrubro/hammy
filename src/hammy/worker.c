#include <concord/discord.h>
#include <concord/log.h>
#include <stdlib.h>
 
#include <hammy/job.h>
#include <hammy/pool.h>
#include <hammy/worker.h>

static void* hammy_worker_main(void* arg) {
    hammy_worker_t* worker = (hammy_worker_t*)arg;
    hammy_pool_t* pool = worker->pool;

    log_info("[worker %d] Started", worker->id);

    for (;;) {
        pthread_mutex_lock(&pool->lock);

        // while instead of if, because pthread_cond_wait() can spuriously wake up like an ass
        while (pool->count == 0 && !pool->shutdown) {
            pthread_cond_wait(&pool->notEmpty, &pool->lock);
        }

        if (pool->count == 0 && pool->shutdown) {
            pthread_mutex_unlock(&pool->lock);
            break;
        }

        hammy_job_t* job = pool->jobs[pool->head];
        pool->head = (pool->head + 1) % pool->cap;
        pool->count--;
        pool->busy++;

        pthread_mutex_unlock(&pool->lock);

        // From here, the worker owns the job and is responsible for destroying it.
        log_info("[worker %d] Processing job %llu from user %llu", worker->id, job->id, job->user);
        int64_t age = hammy_job_age_ms(job, worker->clientCopy);

        if (age > HAMMY_JOB_MAX_AGE_MS) {
            log_warn("[worker %d] Dropping stale job '%s' (age %lld ms)", worker->id, job->command ? job->command : "unknown", (long long)age);
            hammy_job_reply(job, worker->clientCopy, "Sorry, your command took too long to process and was dropped. Please try again.");
        } else {
            hammy_job_run(job, worker->clientCopy);
        }

        hammy_job_destroy(&job);

        pthread_mutex_lock(&pool->lock);
        pool->busy--;
        pthread_mutex_unlock(&pool->lock);
    }

    log_info("[worker %d] Exiting", worker->id);

    return NULL;
}

bool hammy_worker_start(hammy_worker_t* worker, hammy_pool_t* pool, struct discord* client, int id) {
    if (!worker || !pool || !client) { return false; }

    worker->pool = pool;
    worker->id = id;
    worker->clientCopy = NULL;
    worker->started = false;

    // According to the concord spec, each thread must have its own discord client, so we clone it here.
    // However, concord's buffers, URLs, headers, etc. are NOT shared-safe. They're per-client.
    worker->clientCopy = discord_clone(client);
    if (!worker->clientCopy) {
        log_error("[worker %d] Failed to clone client", id);
        return false;
    }

    if (pthread_create(&worker->thread, NULL, &hammy_worker_main, worker) != 0) {
        log_error("[worker %d] Failed to create thread", id);
        discord_cleanup(worker->clientCopy);
        worker->clientCopy = NULL;

        return false;
    }

    worker->started = true;

    return true;
}

void hammy_worker_join(hammy_worker_t* worker) {
    if (!worker) { return; }

    if (worker->started) {
        pthread_join(worker->thread, NULL);
        worker->started = false;
    }

    if (worker->clientCopy) {
        discord_cleanup(worker->clientCopy);
        worker->clientCopy = NULL;
    }
}
