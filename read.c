#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFF_SIZE 1

int main(int argc, const char *argv[])
{
	int n;
	char buf[BUFF_SIZE];

	while((n= read(0,buf,BUFF_SIZE))>0)
		if(write(1,buf,n)!=n)
			printf("write error\n");
	if(n<0)
		printf("read error\n");

	 exit(0);
}

