/**

               */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define _Ull unsigned long long
#define IP "0.0.0.0"
#define port 8080
#define BUFFER_SIZE 4096

struct sockaddr_in addr;
const char *http_request = "GET /joo HTTP/1.1\r\nHost: 0.0.0.0:8080\r\nConnection: close\r\n\r\n";

signed main(int argc,char* argv[]){ 
  int sock = socket(AF_INET,SOCK_STREAM,0);
  if(sock < 0){
    printf("Sock Spawn Failed! Code ([%d])\n",sock);
    return(sock);
  }
  memset(&addr,0,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if(inet_pton(addr.sin_family,IP,&addr.sin_addr) <= 0){
    perror("Error");
    close(sock);
    return(1);
}

  if(connect(sock,(const struct sockaddr*)&addr,sizeof(addr)) < 0){
    perror("Connection Failed");
    close(sock);
    exit(EXIT_FAILURE);
  }
  else{
    puts("Connection Made!");
  }

  if(send(sock,http_request,strlen(http_request),0) == -1){
    perror("Failed to send request");
    close(sock);
    exit(EXIT_FAILURE);
}
  else{
    puts("Sent");
  }

  return(0);
}
