#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *fun1(void *argv);
void *fun2(void *argv);
void registration(void *argv);
void unregistration(int excute, int num);
void cleanup_f(void *argv);

int main(void) {
	pthread_t th1, th2;
	void     *retval1 = NULL, *retval2 = NULL;
	int		  ret = 0;

	//XXX 测试线程创建
	ret = pthread_create(&th1, NULL, fun1, NULL);
	if (ret != 0) {
		printf("线程1创建:%s\n", strerror(ret));
		return -1;
	}
	ret = pthread_create(&th2, NULL, fun2, NULL);
	if (ret != 0) {
		printf("线程2创建:%s\n", strerror(ret));
		return -1;
	}

	//XXX 线程取消
	//在th1的函数中取消线程2

	//XXX 线程清理函数注册
	//在线程函数中注册清理函数

	//XXX 线程分离
	//利用线程分离，查看分离后pthread_join能够获取退出值
	ret = pthread_join(th1, &retval1);
	if (ret != 0) {
		printf("线程1连接:%s\n", strerror(ret));
		return -1;
	}
	ret = pthread_join(th2, &retval2);
	if (ret != 0) {
		printf("线程2连接:%s\n", strerror(ret));
		return -1;
	}

	printf("线程1退出：%s\t线程2退出：%s\n", (char *)retval1, (char *)retval2);
	return 0;
}

void *fun1(void *argv) {
	if (argv == NULL)
		return (void*)1;
	registration(NULL);
	printf("线程1的函数：%s\n", (char*)argv);
	return (void*)1;
}

void *fun2(void *argv) {
	if (argv == NULL)
		pthread_exit((void*)2);
	registration(NULL);
	printf("线程2的函数：%s\n", (char*)argv);
	pthread_exit((void*)2);
}
	
void registration(void *argv) {
	pthread_cleanup_push(cleanup_f, (void*)1);
	pthread_cleanup_push(cleanup_f, (void*)2);
	pthread_cleanup_push(cleanup_f, (void*)3);
}

void unregistration(int excute, int num) {
	for (int i = 0; i < num; i++)
		pthread_cleanup_pop(excute);
}
	
void cleanup_f(void *argv) {
	printf("注册函数:%d\n", (int)*argv);
}
