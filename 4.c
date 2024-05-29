#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigintHandler(int signal) {
    printf("Caught SIGINT signal (Ctrl+C)\n");
}

int main() {
    // Registering signal handler for SIGINT
    signal(SIGINT, sigintHandler);

    printf("Press Ctrl+C to send a SIGINT signal\n");

    // Infinite loop to keep the program running
    while(1) {
        // Sleep for a second to prevent the loop from consuming too much CPU
        sleep(1);
    }

    return 0;
}
