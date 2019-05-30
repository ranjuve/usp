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
#include<signal.h>
struct sigaction sig;
void handler(int val)
{
    printf("Interrupt recieved\n");
    sig.sa_handler=SIG_DFL;
    sigaction(SIGINT,&sig,0);
}
int main()
{
    sig.sa_flags=0;
    sigemptyset(&sig.sa_mask);
    sigaddset(&sig.sa_mask,SIGINT);
    sig.sa_handler=handler;
    sigaction(SIGINT,&sig,0);
    while(1)
    {
        printf("Progress is happiness\n");
        sleep(1);
    }
}