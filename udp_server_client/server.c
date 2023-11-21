#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // Create a UDP socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to an address
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(8080);

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Receive messages from the client
  char buffer[1024];
  socklen_t addrlen = sizeof(servaddr);

  while (1) {
    int recvlen = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &addrlen);
    if (recvlen < 0) {
      perror("recvfrom");
      exit(1);
    }

    printf("Client Says: %s\n", buffer);

    // Send a confirmation message back to the client
    char response[] = "I am fine, thank you.";
    int sentlen = sendto(sockfd, response, sizeof(response), 0, (struct sockaddr *)&servaddr, addrlen);
    if (sentlen < 0) {
      perror("sendto");
      exit(1);
    }

    printf("Response sent.\n");
  }

  close(sockfd);

  return 0;
}

