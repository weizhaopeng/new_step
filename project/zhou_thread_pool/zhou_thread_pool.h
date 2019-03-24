#ifndef _ZHOU_THREAD_POOL_H_
#define _ZHOU_THREAD_POOL_H_

//声明函数指针类型，其实好像是void*类型
typedef void (*zhou_fun)(void*)
//定义任务结点内容
typedef struct task {
	void *argv;
	zhou_fun handler;
	struct task *next;
} task_t;
//定义任务队列（链表任务队列）
typedef struct task_queue {
	struct task_queue *head;
	struct task_queue **tail;
	unsigned int task_max;
	unsigned int task_current;
} task_queue_t;
//定义线程池,XXX 我们经常定义的_t表示的是typedef的转型
typedef struct thread_pool {
	pthread_mutex_t mutex;
	pthread_cond_t  cond;
	task_queue 	    tasks;

	unsigned int 	thread_num;
	unsigned int	thread_stack_size;
} thread_pool_t;
//定义线程池的配置结构体
typedef struct thread_pool_conf {
	unsigned int thread_num;
	unsigned int thread_stack_size;
	unsigned int task_max;
} thread_pool_conf_t;

//XXX 初始化线程池


#endif

