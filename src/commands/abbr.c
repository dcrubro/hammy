#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/refdb.h>
#include <hammy/utils.h>

#define HAMMY_ABBR_ECHO_MAX 16
#define HAMMY_ABBR_CODE_MAX 3072
#define HAMMY_ABBR_TRUNCATED " ... (truncated)"

void hammy_cmd_abbr(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    // Get the qcode argument from the job
    const char* abbr = hammy_job_get_arg(job, "abbreviation");
    if (!abbr) {
        hammy_job_respond(job, client, "Error", "No Abbreviation provided for Abbreviation conversion.", true);
        return;
    }

    char body[HAMMY_ABBR_CODE_MAX + sizeof(HAMMY_ABBR_TRUNCATED)]; // Generally, since the bottom pointers can only point to max 128-character strings (set as preprocesor header)
                                                                     // So yeah - if we ever change the above for some reason to stupid values... yeah. Technically "unsafe" but yeah.

    const char* str = NULL;
    const char* context = NULL;

    if (!hammy_refdb_get_abbr(refdb, abbr, &str, &context)) {
        hammy_job_respond(job, client, "Abbreviation Not Found!", "Failed to find the Abbreviation specified. Please check your query!", true);
        return;
    }

    hammy_to_uppercase(abbr);
    
    snprintf(body, sizeof(body), "Abbreviation: `%s`\nMeaning: `%s`\nUsage Context: `%s`", abbr, (str ? str : "Not Specified"), (context ? context : "Not Specified"));

    hammy_job_respond(job, client, "Abbreviation Conversion", body, false);
}
