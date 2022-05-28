#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

sig_atomic_t child_exit;

void handler(int sn) {
    int ch_exit;
    pid_t ch_pid = wait(&ch_exit);
    printf("Child %d exited with status %d\n", ch_pid, ch_exit);
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof sa);
    sa.sa_handler = &handler;
    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork();
    if (pid != 0){
        int sleep_time = 5;
        while ((sleep_time = sleep(sleep_time)) > 0);
    }
    else
        exit(0);
    return 0;
}

