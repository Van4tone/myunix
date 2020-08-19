
#include <stdio.h>

int main(int argc, const char *argv[])
{
	char cbuf[32];
	char buf[32]="print 2010 1111\n";
	printf("hello world\n");
	fprintf(stdout,"hello world");
	sprintf(cbuf,buf);
	printf("%s",cbuf);
	return 0;
}
