#include "process.h"

int main(void) {
	pid_t child0 = 0, child1 = 0;
	int   ret = 0;

	//XXX 创建子进程，显示父进程的pid子进程的pid，ppid
	child0 = fork();
	if (child0 > 0) {
		sleep(2);
		printf("现在是在父进程:\n子进程pid是:%d\n当前进程pid是:%d\n\n", 
			(int)child0, (int)getpid());
	}
	else if (child0 == 0) {
		printf("现在是在子进程：\n子进程pid是:%d\n父进程pid是:%d\n\n", 
			(int)getpid(), (int)getppid());
		abort();
	}
	else if (child0 == -1) {
		perror("创建进程失败");
		return -1;
	}
	puts("测试进程创建成功\n");

	//XXX 测试进程调用exec类函数
	child1 = fork();
	if (child1 == 0) {
		printf("fork2子进程pid=%d, ppid=%d\n", (int)getpid(), getppid());
		ret = execl("./exec", "", "nihao", "wojiao", "weizhaopeng", 
			"魏朝鹏", NULL);
		if (ret == -1) {
			perror("exec函数执行失败");
			return -1;
		}
	}
	else if (child1 > 0) {
		sleep(2);
		printf("fork2父进程pid = %d\n", (int)getpid());
	}
	puts("测试exec类函数完成");

	//XXX 测试金城终止函数
	

	return 0;
}
