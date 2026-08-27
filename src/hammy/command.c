#include <hammy/command.h>

hammy_command_t* hammy_command_create() {
    hammy_command_t* cmd = (hammy_command_t*)malloc(sizeof(hammy_command_t));
    if (!cmd) {
        return NULL;
    }

    // TODO: set defaults
    
    return cmd;
}

void hammy_command_destroy(void* cmd) {
    if (!cmd) {
        return;
    }

    cmd = (hammy_command_t*)cmd;

    // TODO: Other things here eventually

    free(cmd);
}
