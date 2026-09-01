// commands.h
#ifndef HAMMY_COMMANDS_H
#define HAMMY_COMMANDS_H

#include <concord/discord.h>
#include <hammy/types.h>

void hammy_cmd_ping(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);      // Ping
void hammy_cmd_morse(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);     // Text -> Morse
void hammy_cmd_freq(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);      // Frequency lookup
void hammy_cmd_q(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);         // Q-Code lookup
void hammy_cmd_abbr(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);      // Abbreviation lookup
void hammy_cmd_phonetic(const hammy_job_t* job, struct discord* client, hammy_refdb_t* refdb);  // Callsign -> Phonetics

#endif
