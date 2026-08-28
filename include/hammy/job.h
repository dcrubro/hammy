#ifndef HAMMY_JOB_H
#define HAMMY_JOB_H

#include <concord/discord.h>
#include <stdint.h>
#include <hammy/types.h>

struct hammy_job_t {
    char* token; // Interaction token
    u64snowflake id; // Interaction ID
    u64snowflake user; // Interaction User ID
    char* command;
    char** args; // Might be useful to parse into a struct someday? TODO
    int64_t queued_at; // Staleness checks
};

#endif
