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
struct dirent *dir;
DIR *dp;
struct stat mystat;

dp=opendir(".");
if(dp)
{
    while(dir=readdir(dp)!=NULL)
    {
        stat(dir->d_name,&mystat);
        printf("%ld %o %d %d %s %s\n",mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir->d_name);
    }
}
}

