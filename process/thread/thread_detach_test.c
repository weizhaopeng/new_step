#include "thread.h"

static inline void func_1(void *argv);
static inline void func_2(void *argv);
static inline void func_3(void *argv);

static inline void *function1(void *argv);
static inline void *function2(void *argv);

int ret1 = 10, ret2 = 20;

int main(void) {
	int 	  ret = 0;
	void 	 *retval;
	pthread_t th1, th2;

	ret = pthread_create(&th1, NULL, function1, NULL);
	if (ret != 0) {
		strerror(ret);
		return (-1);
	}
	ret = pthread_create(&th2, NULL, function2, (void*)&th1);
	if (ret != 0) {
		strerror(ret);
		return (-1);
	}
	puts("线程创建完成");

	ret = pthread_detach(th1);
	if (ret != 0) {
		strerror(ret);
		return -1;
	}
	puts("线程1被分离（回收）");

	pthread_join(th1, &retval);
	if (retval == PTHREAD_CANCELED) {
		puts("线程1已经被取消");
		return 0;
	}
	else
		printf("线程1返回主线程的值是：%d\n", *(int *)retval);

	return 0;
}

static inline void *
function1(void *argv) {
	pthread_cleanup_push(func_1, NULL);
	pthread_cleanup_push(func_2, NULL);
	pthread_cleanup_push(func_3, NULL);

	if (argv == NULL) {
		sleep(5);
		puts("现在是在线程1中");
		pthread_exit((void*)&ret1);
	}
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	pthread_exit((void*)&ret1);
}

static inline void *
function2(void *argv) {
	pthread_cleanup_push(func_1, NULL);
	pthread_cleanup_push(func_2, NULL);
	pthread_cleanup_push(func_3, NULL);

	puts("现在是在线程2中");
	//pthread_cancel(*(pthread_t*)argv);
	if (argv != NULL)
		return ((void*)&ret2);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	return ((void*)&ret2);
}


static inline void func_1(void *argv) {
	puts("这里是清理函数1");
}
static inline void func_2(void *argv) {
	puts("这里是清理函数2");
}
static inline void func_3(void *argv) {
	puts("这里是清理函数3");
}

