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

int main(int argc,char* argv[])
{
    pid_t pid;
    if(pid=fork()<0)
    {
        printf("error");
    }
    else if(pid==0)  /*first child*/
    {
        if(pid=fork()<0)
        {
            printf("error");
        }
        else if(pid>0)
        {
            exit(0);
        }
            sleep(2);
            printf("Second child, parent pid=%ld\n",(long)getppid());
            exit(0);
        
    }
if(waitpid(pid,NULL,0)!=pid)
printf("error");
exit(0);
}