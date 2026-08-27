#include <string.h>
#include <concord/discord.h>
#include <concord/log.h>

void on_ready(struct discord* client, const struct discord_ready* event) {
    log_info("Logged in as %s", event->user->username);
}

int main(void) {
    ccord_global_init();

    struct discord* client = discord_config_init("config.json");

    discord_set_on_ready(client, &on_ready);
    
    discord_run(client);

    discord_cleanup(client);
    ccord_global_cleanup();
    
    return 0;
}
