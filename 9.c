#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        printf("Child process running...\n");
        // Replace the child process image with a different program
        execl("/bin/ls", "ls", "-l", NULL);
        // If execl returns, it means an error occurred
        perror("exec");
        exit(1);
    } else {
        // This is the parent process
        // Wait for the child process to finish
        wait(NULL);
        printf("Child process completed\n");
    }

    return 0;
}
