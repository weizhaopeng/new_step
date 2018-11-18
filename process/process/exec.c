#include "process.h"

int main(int argc, char *argv[]) {
	puts("现在执行exec可执行文件代码");
	puts("打印传递进来的字符串");
	for (int i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	printf("exec程序进程是%ld,父进程是%ld\n\n", (long)getpid(), (long)getppid());
	
	return 0;
}

		
