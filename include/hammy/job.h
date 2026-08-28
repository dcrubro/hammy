#ifndef HAMMY_JOB_H
#define HAMMY_JOB_H

#include <concord/discord.h>
#include <stdint.h>

typedef struct {
    char* token; // Interaction token
    u64snowflake id; // Interaction ID
    u64snowflake user; // Interaction User ID
    char* command;
    char** args; // Might be useful to parse into a struct someday? TODO
    int64_t queued_at; // Staleness checks
} hammy_job_t;

#endif
