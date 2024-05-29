#include <stdio.h>
#include <stdlib.h> // Include the <stdlib.h> header for the exit() function
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigint_handler(int sig) {
    // Print a message indicating that the SIGINT signal was received
    printf("\nSIGINT signal received. Exiting...\n");
    
    // You might want to perform cleanup tasks here if needed
    // For example, closing files, releasing resources, etc.

    // Exit the program gracefully
    exit(sig);
}

int main() {
    // Register the signal handler function for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        // Error handling if registering the signal handler fails
        perror("signal");
        return 1;
    }

    // Infinite loop to keep the program running until interrupted
    while (1) {
        // Your program logic goes here
        // For demonstration purposes, we'll just print a message every second
        printf("Program is running...\n");
        sleep(1);
    }

    return 0;
}
