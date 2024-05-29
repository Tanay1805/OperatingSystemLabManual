#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256

// Define a structure for the message
struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    pid_t pid;
    int msgid;
    key_t key;
    struct msg_buffer msg;

    // Generate a unique key for the message queue
    key = ftok("msgqprog", 65);

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child process (sender)
    if (pid == 0) {
        printf("Sender process (PID: %d) is running.\n", getpid());

        // Prepare the message
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello, receiver!");

        // Send the message
        if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        printf("Message sent to the receiver.\n");

        // Remove the message queue
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }

        printf("Message queue removed.\n");
    }
    // Parent process (receiver)
    else {
        printf("Receiver process (PID: %d) is running.\n", getpid());

        // Receive the message
        if (msgrcv(msgid, &msg, sizeof(msg), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Message received: %s\n", msg.msg_text);
    }

    return 0;
}
