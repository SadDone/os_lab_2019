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



void closeUPD(int sig){

    exit(0);

}



pid_t pid;

int main() {

    

  const size_t kSize = sizeof(struct sockaddr_in);



  int lfd, cfd;

  int nread;

  char buf[BUFSIZE];

  struct sockaddr_in servaddr;

  struct sockaddr_in cliaddr;

  printf("test1");

  if ((lfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

    perror("socket");

    exit(1);

  }

  printf("test2");

  memset(&servaddr, 0, kSize);

  servaddr.sin_family = AF_INET;

  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  servaddr.sin_port = htons(SERV_PORT);



  if (bind(lfd, (SADDR *)&servaddr, kSize) < 0) {

    perror("bind");

    exit(1);

  }

  printf("test3");



  if (listen(lfd, 5) < 0) {

    perror("listen");

    exit(1);

  }

 

  while (1) {

       printf("test4");

    unsigned int clilen = kSize;

      printf("Start serv\n");

    if ((cfd = accept(lfd, (SADDR *)&cliaddr, &clilen)) < 0) {

      perror("accept");

      exit(1);

    }

    printf("test5");

    int updPort0=SERV_P;

    //

    

    if (send(cfd, &updPort0, sizeof(int), 0) == -1) {

      perror("send problem!1");

      exit(1);

    }

    

    //write(cfd, updPort0, sizeof(int));

    printf("connection established\n");
    //udp client 
    if(fork()==0){
            perror("test udpcient1");
        int sockfd, n;
  char sendline[BUFSIZE], recvline[BUFSIZE + 1];
  struct sockaddr_in servaddr;
  struct sockaddr_in cliaddr;

 

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = (SERV_P);
  if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) < 0) {
    perror("inet_pton problem");
    exit(1);
  }
              perror("test udpcient2");
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket problem");
    exit(1);
  }
            perror("test udpcient3");
 // write(1, "Enter string\n", 13);

  while ((n = read(0, sendline, BUFSIZE)) > 0) {
    if (sendto(sockfd, sendline, n, 0, (SADDR *)&servaddr, SLEN) == -1) {
      perror("sendto problem");
      exit(1);
    }
                perror("test udpcientWhile");

    if (recvfrom(sockfd, recvline, BUFSIZE, 0, NULL, NULL) == -1) {
      perror("recvfrom problem");
      exit(1);
    }
            perror("test udpcientWhile2");
    printf("REPLY FROM SERVER= %s\n", recvline);
  }
  close(sockfd);
    }


  //  pid=fork();

    if(pid==0){

   // signal(SIGUSR1, closeUPD);

    int updPort1=20001;

    //if(pid==0){

        //upd

        //

        printf("test6");

 
        

    exit(0);

}



    //}

//tcp

    //else {

       else {

          int n, syn;

          //printf("Error serv...\n");

        sleep(1);

    for (;;) {

        int buff;

        read(cfd, &buff, sizeof(int));

       if(buff == 5)

            {

                printf("test stop");

                //как прийдет 5 - сигнал по pid (kill)

                break;

            }

        if(buff == 4)

            {

                printf("test close");

                //как прийдет 5 - сигнал по pid (kill)

                kill(pid, SIGUSR1);

                break;

            }

        }

        //отправляем клиенту данные udp

        //читаем клиента бесконечно пока не прийдет код 5

        //как прийдет 5 - сигнал по pid (kill)

    }

    close(cfd);

    printf("test12");

  }

  printf("test13");

  close(lfd);

  

  }



