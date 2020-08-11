#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int fd,newfd;
	char buf[20]="i came form china!";
	off_t fset;

	fd = open("/home/work/test_code/self_ler/IO1/file.txt",O_RDWR);
	newfd = dup(fd);
	// SEEK_CUR 文件当前偏移量+offset
	// SEEK_SET 文件开始处+offset
	// SEEK_END 文件长度+offset
	fset = lseek(newfd,0,SEEK_END);
	write(newfd,buf,sizeof(buf));

	printf("fset is %d\n",fset);
	return 0;
}

