#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/refdb.h>

// Instant command: runs on the gateway thread, sends a fresh response.
void hammy_cmd_freq(const hammy_job_t* job, struct discord* client, const hammy_refdb_t* refdb) {
    // Get the text argument from the job
    const char* freq = hammy_job_get_arg(job, "frequency");
    if (!freq) {
        hammy_job_respond(job, client, "Error", "No frequency provided for lookup.", true);
        return;
    }

    char* endPtr;
    float freqMHz = strtof(freq, &endPtr);

    if (*endPtr != '\0') {
        // Partial conversion, just error out
        hammy_job_respond(job, client, "Error", "An internal error occurred. Please try again.", true);
        return;
    }

    uint64_t freqPlain = (uint64_t)freqMHz * 1000000; // Convert to raw Hz

    
}
