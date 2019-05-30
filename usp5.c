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
#include<setjmp.h>
static void f1(int,int,int,int);
static void f2(void);
static jmp_buf buffer;
static int globval;
int main(int argc,char* argv[])
{
    int autoval;
    register int regval;
    volatile int volval;
    static int statval;
    globval=1;
    autoval=2;
    regval=3;
    volval=4;
    statval=5;

    if(setjmp(buffer)!=0)
    {printf("after longjmp:\n");
printf("globval = %d, autoval = %d, regval = %d, volval = %d, 
statval = %d\n", globval, autoval, regval, volval, statval);
exit(0);
}
    globval=95;
    autoval=96;
    regval=97;
    volval=98;
    statval=99;
f1(autoval,regval,volval,statval);
exit(0);
}
static void f1(int i,int j,int k,int l)
{printf("in f1():\n");
printf("globval = %d, autoval = %d, regval = %d, volval = %d, statval = %d\n", globval, i, j, k, l);
globval=10000;
j=10000;
f2();
}

static void f2(void)
{
    longjmp(buffer,1);
}