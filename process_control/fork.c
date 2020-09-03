#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
int glob = 6;
char buf[] = "a write to stdout\n";

int main(int argc, const char *argv[])
{
	int var;
	pid_t pid;
	var = 88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	//fputs(buf,stdout);
		perror("write error");
	printf("befor fork\n"); // 换行符会冲洗缓冲区。
//	printf("befor fork");

	if((pid = fork())<0)
		perror("fork error");
	else if (pid == 0)
	{
		printf("this is child\n");
		glob++;
		var++;
	}
	else 
	{
		sleep(2);
		printf("this is father\n");
	}
	printf("pid = %d, glob = %d,var = %d\n",getpid(),glob,var);
	return 0;
}

/*

work@DESKTOP-HCJVFTS:~/unix/process_control$ gcc fork.c
work@DESKTOP-HCJVFTS:~/unix/process_control$ ./a.out
a write to stdout
befor fork
this is child
pid = 509, glob = 7,var = 89
this is father
pid = 508, glob = 6,var = 88
work@DESKTOP-HCJVFTS:~/unix/process_control$ ./a.out >1.txt
work@DESKTOP-HCJVFTS:~/unix/process_control$ cat 1.txt
a write to stdout
befor fork
this is child
pid = 513, glob = 7,var = 89
befor fork
this is father
pid = 512, glob = 6,var = 88

write函数是没有缓冲的，在fork之前就调用了write，所以其数据只输出到标准输出一次。

以交互方式运行次程序时printf只输出一次，是因为换行符冲洗了标准输出的缓冲区。
而将标准输出重定向到文件时，printf输出了2次，是因为printf在fork之前调用了一次，当调用fork时该行数据仍在缓冲区中，父进程将数据空间复制到子进程中时，该缓冲区也被复制过来。在exit之前的第二个printf将数据添加到现有的缓冲区内。当每个进程终止时，最终会冲洗其缓冲区的副本。

*/


