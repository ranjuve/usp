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


static void charatatime(char *);
int main(int argc,char* argv[])
{
pid_t pid;
if((pid=fork())<0)
{
    printf("fork error");
}
else if(pid==0)
{
    charatatime("output from child\n");
}
else 
{
    charatatime("output from parent\n");
}
exit(0);
}
static void charatatime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout,NULL);
    for(ptr=str;(c=*ptr++)!=0;)
    {
        putc(c,stdout);
    }
}