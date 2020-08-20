#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("hello world\n");
}

//编译程序时指定c89编译则程序的终止码是随机的
//gcc -std=c89 hello.c
//echo $?  查看终止码

