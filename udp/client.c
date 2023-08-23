#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Port number
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

    // Send and receive data
    char buffer[1024];
    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(client_socket, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

        memset(buffer, 0, sizeof(buffer));
        recvfrom(client_socket, buffer, sizeof(buffer), 0, NULL, NULL);
        printf("Server: %s", buffer);
    }

    // Close the socket
    close(client_socket);

    return 0;
}
