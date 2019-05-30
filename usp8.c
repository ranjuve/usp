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


void daemonize()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("error");
    }
    else if(pid)
    {
        printf("PID of child is %d\n",pid);
        exit(0);
    }
umask(0);
if(chdir("/")<0)
{
    printf("Error changing directory");
}
if(setsid()<0)
{
    printf("Error creating session");
}
printf("Daemon created");
}

int main(int argc,char* argv[])
{
    daemonize();
    system("ps -axj");
    return 0;
}