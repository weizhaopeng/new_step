#include "zhou_thread_pool.h"

//线程池
typedef struct thread_pool_s {
	//任务队列,互斥量，条件变量, 事务数量，
    task_queue_t   *queue;
    pthread_mutex_t mtx;
	pthread_cond_t  cond;
    int   			tasks;

	//队列的最大长度，线程池的名称，默认线程数:线程池的配置
    int   max_queue;
    char *name;
	int  threads
	//线程池写入的日志 
    zhou_log_t *log;
	//char *file;
	//unsigned int line;
}

//线程池配置
typedef struct thread_pool_conf_s {
	int max_queue;
	char *name;
	int threads;
} thread_pool_conf_t;

static inline int thread_pool_init(thread_pool_t *tp, ngx_log_t *log) {

	//事务队列初始化

	//创建互斥量和条件变量

	//日志赋值

	//线程参数创建

	//创建线程，都先运行线程的循环程序

	//线程参数销毁

}

static inline void thread_pool_destroy(ngx_thread_pool_t *tp) {
	//线程函数都退出

	//for循环释放，线程发送信息

	//条件变量释放

	//互斥量释放

}




