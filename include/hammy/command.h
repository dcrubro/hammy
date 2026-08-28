#ifndef HAMMY_COMMAND_H
#define HAMMY_COMMAND_H

#include <stdlib.h>
#include <hammy/types.h>

struct hammy_command_t {
    // TODO: add shit here
    char empty;
};

// Creates the command on the heap, returns NULL if failed.
hammy_command_t* hammy_command_create();

// Destroys a command.
void hammy_command_destroy(void* cmd);

#endif
