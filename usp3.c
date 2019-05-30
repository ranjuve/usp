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
int fd,n;
dp=opendir(".");
if(dp)
{
    while((dir=readdir(dp))!=NULL)
    {
        fd=open(dir->d_name,O_RDWR,0777);
        n=lseek(fd,0,SEEK_END);
        if(!n)
            unlink(dir->d_name);
    }
}
}