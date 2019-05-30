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
    struct utimbuf times;
    struct stat mystat;
    umask(0066);
    if(creat("source.txt",0666)<0)
    {
        printf("error");
        return 0;
    }
stat("source.txt",&mystat);
times.actime=mystat.st_atime;
times.modtime=mystat.st_mtime;
utime("source.txt",&times);
printf("ACCESS time %s\n MODIFICATION time %s\n",
    ctime(&mystat.st_atime),ctime(&mystat.st_mtime));
    printf("ACCESS time %s\n MODIFICATION time %s\n",
    ctime(&times.actime),ctime(&times.modtime));

}