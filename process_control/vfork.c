#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
int glob = 6;

int main(int argc, const char *argv[])
{
	int var;
	pid_t pid;
	var = 88;
	printf("befor fork\n"); // 换行符会冲洗缓冲区。

	if((pid = vfork())<0)
		perror("fork error");
	else if (pid == 0)
	{
		printf("this is child\n");
		glob++;
		var++;
		_exit(0);
	//	exit(0);
	}

	printf("pid = %d, glob = %d,var = %d\n",getpid(),glob,var);
	exit(0);
}



