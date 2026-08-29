#include <concord/discord.h>
#include <concord/discord-internal.h>
#include <concord/log.h>
#include <stdlib.h>

#include <hammy/job.h>
#include <hammy/pool.h>
#include <hammy/worker.h>

// Workaround for a concord 3.0.1 bug. _discord_clone_gateway_cleanup()
// (discord-client.c:833) frees payload.json.table and then frees payload.data
// as well, but payload.data is a jsmnf_pair pointing INTO that table, not a
// separate allocation. Every discord_cleanup() of a clone is therefore an
// invalid free. Clearing the field first skips that free; the table it points
// into is still released, so nothing leaks.
static void hammy_worker_cleanup_clone(struct discord* clone) {
    if (!clone) { return; }

    clone->gw.payload.data = NULL;

    discord_cleanup(clone);
}

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

    // Each thread needs its own client. The queues, pollers and timers are all
    // shared through pointers, but client->registry - the reflect-c registry
    // that serialises request bodies on the calling thread - is not.
    // discord_clone() copies the gateway's *current* payload, so this only
    // works while a dispatch is in flight. See hammy_pool_create().
    worker->clientCopy = discord_clone(client);
    if (!worker->clientCopy) {
        log_error("[worker %d] Failed to clone client", id);
        return false;
    }

    if (pthread_create(&worker->thread, NULL, &hammy_worker_main, worker) != 0) {
        log_error("[worker %d] Failed to create thread", id);
        hammy_worker_cleanup_clone(worker->clientCopy);
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
        hammy_worker_cleanup_clone(worker->clientCopy);
        worker->clientCopy = NULL;
    }
}
