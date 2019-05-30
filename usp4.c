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
    struct stat buf1;
    struct stat buf2;
    struct utimbuf times;
    stat(argv[1],&buf1);
    stat(argv[2],&buf2);
    printf("BEFORE\n");
    printf("ACCESS time %s\n MODIFICATION time %s\n",
    ctime(&buf1.st_atime),ctime(&buf1.st_mtime));

    times.actime=buf2.st_atime;
    times.modtime=buf2.st_mtime;
    utime(argv[1],&times);

    stat(argv[1],&buf1);
    printf("AFTER\n");
    printf("ACCESS time %s\n MODIFICATION time %s\n",
    ctime(&buf1.st_atime),ctime(&buf1.st_mtime));

}