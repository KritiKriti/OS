#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    // Create a child process
    pid_t pid = fork();

    if (pid < 0)
    {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // This is the child process
        printf("Child Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }
    else
    {
        // This is the parent process
        printf("Parent Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}