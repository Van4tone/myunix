#include <stdio.h>

int main(int argc, const char *argv[])
{
	int c;
#if 0
	while((c = getc(stdin))!=0)
			if(putc(c,stdout)==0)
			printf("output error\n");
#endif
	
	while((c = fgetc(stdin))!=0)
		if(fputc(c,stdout)==0)
			printf("output error\n");
	return 0;
}
