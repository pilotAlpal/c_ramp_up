#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid != 0)
        sleep(60);
    else
        exit(0);
    return 0;
}
