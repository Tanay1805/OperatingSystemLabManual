#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello, child process!";

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process
        close(pipefd[1]);  // Close unused write end

        char buffer[BUFFER_SIZE];
        ssize_t numRead;

        // Read from the pipe
        numRead = read(pipefd[0], buffer, BUFFER_SIZE);
        if (numRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child process received message: %s\n", buffer);

        close(pipefd[0]);  // Close read end
        exit(EXIT_SUCCESS);
    } else {  // Parent process
        close(pipefd[0]);  // Close unused read end

        // Write to the pipe
        if (write(pipefd[1], message, strlen(message)) != strlen(message)) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("Parent process sent message to child: %s\n", message);

        close(pipefd[1]);  // Close write end
        wait(NULL);  // Wait for child to finish
        exit(EXIT_SUCCESS);
    }

    return 0;
}
