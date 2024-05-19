#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define RESSIZE 8192
#define BUFSIZE 4096
#define PORT 8880

void serve_index_html(int client_socket) {
  char res[RESSIZE] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
  int fd = open("../res/index.html", O_RDONLY);
  char buf[BUFSIZE];
  read(fd, buf, sizeof(buf));
  strcat(res, buf);
  write(client_socket, res, sizeof(res));
  close(fd);
  printf("Served index.html to client %d\n", client_socket);
}

int main(int argc, char *argv[]) {
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_size = sizeof(client_addr);
  int server_socket, client_socket;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  printf("Server socket created\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
  printf("Server socket bound to port %d\n", PORT);

  listen(server_socket, 5);
  printf("Server is listening\n");

  while (true) {
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr,
                           &client_addr_size);
    printf("Accepted connection from client %d\n", client_socket);

    serve_index_html(client_socket);
    close(client_socket);
    printf("Closed connection with client %d\n", client_socket);
  }

  close(server_socket);
  printf("Server socket closed\n");
  return 0;
}
