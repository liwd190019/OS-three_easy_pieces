#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {
  // Create a UDP socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set the destination address
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(8080);
  
  char message[256];
  if (argc > 1)
    // strcpy(message, argv[1]);
    for(int i = 1; i < argc; i++){
      strcat(message, argv[i]);
      strcat(message, " ");
    }
  else
    strcpy(message, "Hello, how are you?");
  int sentlen = sendto(sockfd, message, sizeof(message), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (sentlen < 0) {
    perror("sendto");
    exit(1);
  }

  printf("Hello message sent.\n");

  // Receive the confirmation message from the server
  char buffer[1024];
  socklen_t addrlen = sizeof(servaddr);
  int recvlen = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &addrlen);
  if (recvlen < 0) {
    perror("recvfrom");
    exit(1);
  }

  printf("Server Says: %s\n", buffer);

  close(sockfd);

  return 0;
}
