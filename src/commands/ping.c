#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>

#include <hammy/command.h>
#include <hammy/job.h>

// Discord epoch, for turning a snowflake back into a wall-clock time.
#define HAMMY_DISCORD_EPOCH_MS 1420070400000LL
 
static int64_t hammy_snowflake_to_ms(u64snowflake id) {
    return (int64_t)(id >> 22) + HAMMY_DISCORD_EPOCH_MS;
}
 
// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_ping(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    (void)refdb;

    // Gateway heartbeat round trip, as measured by Concord.
    int gatewayMs = discord_get_ping(client);
 
    // Time from Discord minting the interaction to us handling it. This is the
    // number that degrades under load, so it is the one worth showing.
    int64_t handledMs = (int64_t)discord_timestamp(client) - hammy_snowflake_to_ms(job->id);
 
    char body[256];
    snprintf(body, sizeof(body),
             "Gateway: `%d ms`\nHandled in: `%" PRId64 " ms`",
             gatewayMs, handledMs);
 
    hammy_job_respond(job, client, "Pong!", body, false);
}
