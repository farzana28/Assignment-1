#include<stdio.h>

#include<sys/socket.h>

#include<netdb.h>

#include<string.h>

#include<sys/types.h>

#include<netinet/in.h>

#include<arpa/inet.h>

#include<unistd.h>

#include<stdlib.h>



#define MAXDATASIZE 100

void main()

{

int sd,i=0,len,l,s,sd1,si,port;

struct sockaddr_in ser,cli;

char msg[20],rmsg[50];

char buf[MAXDATASIZE];



if((sd=socket(AF_INET,SOCK_STREAM,0))<0)

{

  printf("\n\t Error in socket");

  exit(0);

}



bzero(&ser,sizeof(ser));

ser.sin_family=AF_INET;

printf("\nEnter the port number : ");

scanf("%d",&port);

ser.sin_port=htons(port);

ser.sin_addr.s_addr=htonl(INADDR_ANY);

if(bind(sd,(struct sockaddr*)&ser,sizeof(ser)) <0)

{

  printf("\n\t Error in bind");

  exit(0);

}



if(listen(sd,5) <0)

{

 printf("\n\t Error in Listen");

exit(0);

}



si=sizeof(cli);

if((sd1=accept(sd,(struct sockaddr*)&cli,&si)) <0)

{

 printf("\n\t Error in Accept");

exit(0);

}



do

{

 recv(sd1,msg,50,0);

 printf("\n\t Clinet Msg Received : %s ",msg);

 printf("\n\t Enter Server String : ");

 gets(buf);

 send(sd1,buf,50,0);

}



while((strcmp(buf,"exit"))!=0);

close(sd);

exit(0);

}


