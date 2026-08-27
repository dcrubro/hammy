#include <string.h>
#include <signal.h>
#include <concord/log.h>

#include <hammy/bot.h>

static void on_signal(int sig) {
    (void)sig;
    discord_shutdown_all();
}

void on_ready(struct discord* client, const struct discord_ready* event) {
    (void)client;
    log_info("Logged in as %s", event->user->username);
}

int main(void) {
    struct sigaction sa = { 0 };
    sa.sa_handler = &on_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;   /* deliberately no SA_RESTART */
    
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGINT,  &sa, NULL);

    ccord_global_init();

    hammy_bot_t* bot = hammy_bot_create();
    if (!bot) {
        log_error("Hammy Bot creation returned NULL! Bailing!");
        ccord_global_cleanup();

        return 1;
    }

    hammy_bot_set_on_ready(bot, &on_ready);
    hammy_bot_run(bot); // This will block and exit afterwards

    hammy_bot_destroy(&bot);
    
    ccord_global_cleanup();
    
    return 0;
}
