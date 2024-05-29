#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        printf("Child process: Parent PID = %d\n", getppid());
        // Simulate some work in the child process
        sleep(2);
        printf("Child process: Exiting\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Waiting for child process to terminate\n");
        
        // Wait for the child process to terminate
        pid_t child_pid = wait(&status);
        
        // Check if the child terminated normally
        if (WIFEXITED(status)) {
            printf("Parent process: Child %d terminated with exit status %d\n", child_pid, WEXITSTATUS(status));
        } else {
            printf("Parent process: Child %d terminated abnormally\n", child_pid);
        }
        
        printf("Parent process: Exiting\n");
    }

    return 0;
}
