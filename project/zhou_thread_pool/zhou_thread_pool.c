#include "zhou_thread_pool.h"

thread_pool_t *thread_pool_init(thread_pool_conf_t *conf) {
	thread_pool_t *pool = NULL;
	int			   error_flag_mutex = 0,
				   error_flag_cond  = 0;
	pthread_attr_t attr;

	do {
		//检查线程池的配置是否合法
		if (thread_pool_conf_check(conf) == 1)
			break;
		
		pool = malloc(sizeof(thread_pool_t);
		if (pool == NULL)
			break;
		//根据配置数据来初始化线程池和任务队列
		pool->thread_num = conf->thread_num;
		pool->thread_stack_size = conf->thread_stack_size;
		pool->tasks.task_max = conf->task_max;
		pool->task.task_current = 0;
		//初始化任务队列
		task_queue_init(&pool->tasks);
		//创建一个pthread_key_t用来访问全局变量
		if (thread_key_create() != 0) {
			free(pool);
			break;
		}
		if (thread_mutex_create(&pool->mutex) != 0) {
			thread_key_destroy();
			free(pool);
			break;
		}
		if (thread_pool_create() != 0) {
			thread_key_destroy();
			thread_mutex_destroy(&pool->mutex);
			thread_cond_destroy(&pool-cond);
			free(pool);
			break;
		}

		return pool;
	} while(0);

	return NULL;
}


//添加任务
static inline int task_queue_add(thread_pool_t *pool, 
		zhou_fun handler, void *argv) {
	task_t *task = NULL;

	task = malloc(sizeof(task_t));
	if (task == NULL) 
		return -1;
	
	task->handler = handler;
	task->argv = argv;
	task->next = NULL;
	if (pthread_mutex_lock(&pool->mutex) != 0) {
		free(task);
		return -1;
	}

	do {
		if 




		



