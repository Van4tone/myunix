#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>


static void f1(int,int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globalval;

int main(int argc, const char *argv[])
{
	int autoval;
	register int regval;
	volatile int volval;
	static int statval;

	globalval = 1;
	autoval   = 2;
	regval    = 3;
	volval    = 4;
	statval   = 5;

	if(setjmp(jmpbuffer)!=0)
	{
		printf("after longjmp!\n");
		printf("globalval = %d, autoval = %d, regval = %d, volval = %d, statval = %d\n",globalval,autoval,regval,volval,statval);
		exit(0);
	}

	globalval = 10;
	autoval   = 11;
	regval    = 12;
	volval    = 13;
	statval   = 14;
	f1(autoval,regval,volval,statval);
	exit(0);
}

static void f1(int i,int j,int k,int l)
{
	printf("this is f1\n");
	printf("globalval = %d, autoval = %d, regval = %d, volval = %d, statval = %d\n",globalval,i,j,k,l);

	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer, 1);
}

/*

work@ubuntu:~/test_code/self_ler/myunix/thread_env$ gcc jump.c
work@ubuntu:~/test_code/self_ler/myunix/thread_env$ ./a.out
this is f1
globalval = 10, autoval = 11, regval = 12, volval = 13, statval = 14
after longjmp!
globalval = 10, autoval = 11, regval = 12, volval = 13, statval = 14

work@ubuntu:~/test_code/self_ler/myunix/thread_env$ gcc -O jump.c
work@ubuntu:~/test_code/self_ler/myunix/thread_env$ ./a.out
this is f1
globalval = 10, autoval = 11, regval = 12, volval = 13, statval = 14
after longjmp!
globalval = 10, autoval = 2, regval = 3, volval = 13, statval = 14

优化编译后，全局、静态、易失变量不受优化影响。在调用longjmp后他的值是最近呈现的值。
自动变量和寄存器变量受到影响。

故此，要编写一个使用非局部跳转的可移植程序，必须使用volatile属性。

*/






