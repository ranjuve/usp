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
#include<ctype.h>
#define MAX 80
int main(int argc,char* argv[])
{
    char buffer[MAX];
    int in,out,n;
    mkfifo("server_to_client",0777);
    mkfifo("client_to_server",0777);
    while(1)
    {
    out=open("server_to_client",O_RDWR,0777);
    in=open("client_to_server",O_RDWR,0777);
    memset(buffer,0,MAX);
    printf("Waiting for message\n");
    n=read(in,buffer,MAX);
    printf("Message:%s\n",buffer);
    buffer[0]=toupper(buffer[0]);
    printf("Sending reply\n");
    write(out,buffer,n);
    close(in);
    close(out);
    }
    return 0;
    }
