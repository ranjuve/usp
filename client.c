#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<time.h>
#include<utime.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h> 
#define MAX 80
int main(int argc,char* argv[])
{
    char buffer[MAX];
    int in,out,n;
    in=open("server_to_client",O_RDWR,0777);
    out=open("client_to_server",O_RDWR,0777);

    printf("Sending message");
    n=strlen(argv[1]);
    write(out,argv[1],n);
    read(in,buffer,n);
    buffer[n]='\0';
    printf("Message recived:%s\n",buffer);
    close(in);
    close(out);
}