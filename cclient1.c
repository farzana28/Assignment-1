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

int sd,i=0,len,port;

struct sockaddr_in ser;

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





if(connect(sd,(struct sockaddr*)&ser,sizeof(ser)) <0)

{

printf("\n\t Error in bind");

exit(0);

}





do

{

printf("\n\t Enter the Client String :");

gets(buf);

send(sd,buf,50,0);



recv(sd,rmsg,50,0);

printf("\n\t  Server Msg Received : %s ",rmsg);



}



while((strcmp(buf,"exit"))!=0);

close(sd);

}

