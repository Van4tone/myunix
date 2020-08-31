#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>


#define TOK_ADD 5
jmp_buf jmpbuf;

void cmd_add(void)
{
	int token;
	token = get_token();
	if(token <0)
		longjmp(jmpbuf,1);
}


int main(int argc, const char *argv[])
{
	char line[MAXLINE];
	if(setjmp(jmpbuf)!=0)
		printf("setjmp error!\n");
	wwhile(fgets(line,MAXLINE, stdin)!=NULL)
		do_line(line);
	exit(0);
}
