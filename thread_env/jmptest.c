#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE   1024
#define TOK_ADD 5

char *tok_ptr;

int get_token(void)
{

}

void cmd_add(void)
{
	int token;
	token = get_token();
}

void do_line(char *ptr)
{
	int cmd;
	tok_ptr = ptr;
	while((cmd = get_token())>0)
	{
		switch(cmd)
		{
		case TOK_ADD:
			cmd_add();
			break;
		}
	}
	
}

int main(int argc, const char *argv[])
{
	char line[MAXLINE];
	while(fgets(line,MAXLINE,stdin)!=NULL)
		do_line(line);
	exit(0);
}

/*
 * 栈的底部--------------------- 高地址
 *         |main 的栈帧        |
 *         |-------------------| main 的栈顶
 *         |                   |   
 *         |do_line 的栈帧     |
 *         |-------------------| do_line 的栈顶
 *         |                   |
 *         |cmd_add 的栈帧     |
 *         |-------------------| cmd_add 的栈顶
 *         |                   |
 *         |get_token 的栈帧   |
 *         |-------------------| get_token 的栈顶
 *         |                   |
 *        \|/                   |地址值
 *         | 
 *       栈扩展的方向
 *
 *  数组 line  在 main    的栈帧中
 *  整形 cmd   在 do_line 的栈帧中
 *  整形 token 在 cmd_add 的栈帧中
 *
 * 栈不一定是向地地址扩展，可以使用链表实现栈帧。
 */

