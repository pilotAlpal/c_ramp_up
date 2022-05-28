#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

sig_atomic_t sig_user1 = 0;

void handler(int sn)
{
    ++sig_user1;
}

int main()
{
    printf("My pid is %d\n", (int) getpid());
    struct sigaction sa;
    memset(&sa, 0, sizeof sa);
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    int sleep_time = 30;
    while ((sleep_time = sleep(sleep_time)) > 0);
    printf("Signal SIGUSR1 received %d times\n", sig_user1);
    return 0;
}
