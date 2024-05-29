#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d\n", getpid());
        printf("Child's parent process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("This is the parent process. PID: %d\n", getpid());
        printf("Parent's child process ID: %d\n", pid);
    }

    // Both processes execute this
    printf("Process %d: Exiting\n", getpid());

    return 0;
}
