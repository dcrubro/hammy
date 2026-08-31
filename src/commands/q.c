#include <concord/discord.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include <hammy/command.h>
#include <hammy/job.h>
#include <hammy/refdb.h>
#include <hammy/utils.h>

#define HAMMY_QCODE_ECHO_MAX 16
#define HAMMY_QCODE_CODE_MAX 3072
#define HAMMY_QCODE_TRUNCATED " ... (truncated)"

void hammy_cmd_q(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb) {
    // Get the qcode argument from the job
    const char* qcode = hammy_job_get_arg(job, "q-code");
    if (!qcode) {
        hammy_job_respond(job, client, "Error", "No text provided for Q-Code conversion.", true);
        return;
    }

    char body[HAMMY_QCODE_CODE_MAX + sizeof(HAMMY_QCODE_TRUNCATED)]; // Generally, since the bottom pointers can only point to max 128-character strings (set as preprocesor header)
                                                                     // So yeah - if we ever change the above for some reason to stupid values... yeah. Technically "unsafe" but yeah.

    const char* questionStr = NULL;
    const char* answerStr = NULL;

    if (!hammy_refdb_get_qcode(refdb, qcode, &questionStr, &answerStr)) {
        hammy_job_respond(job, client, "Q-Code Not Found!", "Failed to find the Q-Code specified. Please check your query!", true);
        return;
    }

    hammy_to_uppercase(qcode);
    
    snprintf(body, sizeof(body), "Q-Code: `%s`\nQuestion: `%s`\nAnswer: `%s`", qcode, (questionStr ? questionStr : "Not Specified"), (answerStr ? answerStr : "Not Specified"));

    hammy_job_respond(job, client, "Q-Code Conversion", body, false);
}
