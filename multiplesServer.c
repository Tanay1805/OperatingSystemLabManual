#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int main() {
    int server_socket, max_sd, activity;
    struct sockaddr_in server_address, client_address;
    fd_set readfds;
    int client_sockets[MAX_CLIENTS];
    char buffer[MAX_BUFFER_SIZE];

    // Create a UDP socket
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (const struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP server is listening on port %d\n", PORT);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        FD_ZERO(&readfds);

        FD_SET(server_socket, &readfds);
        max_sd = server_socket;

        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
                if (sd > max_sd) {
                    max_sd = sd;
                }
            }
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity == -1) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_socket, &readfds)) {
            socklen_t client_address_len = sizeof(client_address);
            ssize_t bytes_received = recvfrom(server_socket, buffer, MAX_BUFFER_SIZE, 0,(struct sockaddr *)&client_address, &client_address_len);
            if (bytes_received == -1) {
                perror("recvfrom failed");
                continue;
            }

            buffer[bytes_received] = '\0';

            printf("Received from client (%s:%d): %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            if (sendto(server_socket, buffer, bytes_received, 0,(const struct sockaddr *)&client_address, client_address_len) == -1) {
                perror("sendto failed");
                continue;
            }

            printf("Echoed back to client\n");
        }
    }

    close(server_socket);

    return 0;
}
