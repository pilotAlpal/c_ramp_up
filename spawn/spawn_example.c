#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int spawn(char* program, char** arg_list)
{
    pid_t pid = fork(); 
    if (pid != 0)
        return pid;
    else {
        execvp(program, arg_list);
        printf("Error calling execvp\n");
        abort();
    }
}

int main(int argc, char** argv)
{
    pid_t child_pid;
    int child_status;
    if (argc == 1) {
        char* args[] = {
            "ls",
            "-lart",
            "/",
            NULL
        };
        child_pid = spawn(args[0], args);
    }
    else
        child_pid = spawn(argv[1], &argv[1]);
    waitpid(child_pid, &child_status, 0);
    if (WIFEXITED(child_status))
        printf("Child exited normally with status: %d\n", WEXITSTATUS(child_status));
    else
        printf("Child exited abnormally\n");
    printf("main program done.\n");
    return 0;
}
