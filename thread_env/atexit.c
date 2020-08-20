#include<stdio.h>
#include<stdlib.h>

void func1(void)
{
	printf("the first func\n");
}

void func2(void)
{
	printf("the second func\n");
}

int main(int argc, const char *argv[])
{
	if(atexit(func2)==0)
		printf("register func2 success!\n");

	if(atexit(func1)==0)
		printf("register func1 success!\n");

	if(atexit(func1)==0)
		printf("register func1 success!\n");

	return 0;
}
