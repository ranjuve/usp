#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
    int s,d,n;
    char buf;
    int size;
    int i;
    s=open(argv[1],O_RDONLY);
    d=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT);

    size=lseek(s,0,SEEK_END);
    printf("SIze %d",size);
    for(i=size-1;i>=0;i--)
    {
        lseek(s,i,SEEK_SET);
        n=read(s,&buf,1);
        n=write(d,&buf,1);

    }
    close(s);
    close(d);
    return 0;


}