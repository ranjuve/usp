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

void callback()
{
    printf("Interrupt recieved\n");
    (void)signal(SIGINT,SIG_DFL);
}
int main()
{
    int ch,i=0;
    printf("Enter choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            (void)signal(SIGINT,callback);
            break;
        }
        case 2:
        {
            (void)signal(SIGINT,SIG_IGN);
            break;
        }
    }
    while(1)
    {
        sleep(1);
        printf("Press CTRL+C...\n");
        i=i+1;
        if((i==10)&&(ch==2))
        {
            (void)signal(SIGINT,SIG_DFL);
        }

    }
    return 0;
}
