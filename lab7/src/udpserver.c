#include <netinet/in.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#include <sys/socket.h>

#include <sys/types.h>

#include <unistd.h>



#include<signal.h>



#define SERV_PORT 10050

#define SERV_P 20001

#define BUFSIZE 1024

#define SADDR struct sockaddr

#define SADDR struct sockaddr2



#define SLEN sizeof(struct sockaddr)

int main(void)
{
    int gfd, n;

  char mesg[BUFSIZE], ipadr[16];

  struct sockaddr_in servaddr2;

  struct sockaddr_in cliaddr2;
  
  struct sockaddr_in cliaddr;


  if ((gfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {

    perror("socket problem");

    exit(1);

  }

  printf("test7");



  memset(&servaddr2, 0, SLEN);

  servaddr2.sin_family = AF_INET;

  //servaddr2.sin_addr.s_addr = htonl(INADDR_ANY);

  servaddr2.sin_addr.s_addr = inet_addr("127.0.0.1");

  servaddr2.sin_port = htons(SERV_P);



  if (bind(gfd, (SADDR *)&servaddr2, SLEN) < 0) {

    perror("bind problem100");

    exit(1);

  }

  printf("test8");

  printf("SERVER starts...\n");

  perror("read?0");

  int upd_stop_flag=1;

  perror("read?1");

  while (upd_stop_flag==1) {

      perror("read?2");

    unsigned int len = sizeof(struct sockaddr);

    perror("read?3");

    if ((n = recvfrom(gfd, mesg, BUFSIZE, 0, (SADDR *)&cliaddr2, &len)) < 0) {

      perror("recvfrom");

      exit(1);

    }

    perror("test9");

    mesg[n] = 0;

    /*

    printf("REQUEST %s      FROM %s : %d\n", mesg,

           inet_ntop(AF_INET, (void *)&cliaddr2.sin_addr.s_addr, ipadr, 16),

           ntohs(cliaddr.sin_port));

           */

perror("test9!");

    if (sendto(gfd, mesg, n, 0, (SADDR *)&cliaddr2, len) < 0) {

      perror("sendto");

      exit(1);

      }

      perror("test10");

    }
}
