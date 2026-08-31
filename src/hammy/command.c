#include <stddef.h>
#include <string.h>

#include <hammy/command.h>

// Handlers live in src/hammy/commands/. Declared here rather than in a header
// so adding a command touches exactly two places: its own .c file and this
// table.
void hammy_cmd_ping(const hammy_job_t* job, struct discord* client, const hammy_refdb_t* refdb);
void hammy_cmd_morse(const hammy_job_t* job, struct discord* client, const hammy_refdb_t* refdb);
void hammy_cmd_freq(const hammy_job_t* job, struct discord* client, const hammy_refdb_t* refdb);

// TODO: Temporary - move to a proper options system; e.g. a vector of heap-allocated options or something. For now, just point at static storage.
static struct discord_application_command_option morse_opts[] = {
    { .type = DISCORD_APPLICATION_OPTION_STRING, .name = "text",
      .description = "Text to convert to Morse code", .required = true },
};

static struct discord_application_command_options morse_opts_struct = {
    .size = 1,
    .array = morse_opts
};

static struct discord_application_command_option freq_opts[] = {
    { .type = DISCORD_APPLICATION_OPTION_STRING, .name = "frequency",
      .description = "Frequency in MHz", .required = true },
    { .type = DISCORD_APPLICATION_OPTION_STRING, .name = "country",
       .description = "Country code to look up (e.g. US) - Defaults to US if none specified.", .required = false },
};

static struct discord_application_command_options freq_opts_struct = {
    .size = 2,
    .array = freq_opts
};

// The command table. Pure data - no allocation, no lifetime, no destructor.
// Copying an entry into the bot's vector is a plain struct copy, and the vector
// may be created with a NULL destructor hook.
//
// Field order: name, description, options, handler, instant.
static const hammy_command_t hammy_builtin_commands[] = {
    { "ping", "Check whether Hammy is alive and how fast it is responding", NULL, &hammy_cmd_ping, true },
    { "morse", "Text to and from Morse code", &morse_opts_struct, &hammy_cmd_morse, true },
    { "freq", "Band, segment and who can transmit", &freq_opts_struct, &hammy_cmd_freq, true }

    // Tier 0 commands go here as they land. All pure computation, so instant:
    //   { "grid",  "Maidenhead locator conversions", &grid_opts,  &hammy_cmd_grid,  true },
    //   { "morse", "Text to and from Morse code",    &morse_opts, &hammy_cmd_morse, true },
    //   { "band",  "What band is a frequency in",    &band_opts,  &hammy_cmd_band,  true },
    //
    // Anything touching the backend API, a database or the network is NOT
    // instant:
    //   { "call",  "Look up a callsign", &call_opts, &hammy_cmd_call, false },
};

const hammy_command_t* hammy_command_builtins(size_t* outCount) {
    if (outCount)
        *outCount = sizeof(hammy_builtin_commands) / sizeof(hammy_builtin_commands[0]);

    return hammy_builtin_commands;
}

const hammy_command_t* hammy_command_find(const hammy_command_t* commands, size_t count,
                                          const char* name) {
    if (!commands || !name) return NULL;

    for (size_t i = 0; i < count; i++) {
        if (commands[i].name && strcmp(commands[i].name, name) == 0)
            return &commands[i];
    }

    return NULL;
}

bool hammy_command_is_instant(const hammy_command_t* command) {
    return command && command->instant;
}
