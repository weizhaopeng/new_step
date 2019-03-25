#ifndef _ZHOU_THREAD_H_
#define _ZHOU_THREAD_H_

//线程任务结点：nginx中的线程任务task是以链表的形式表示队列，来实现任务的出入
typedef struct task_s {
    void (*handler)(void *argv, zhou_log_t *log);
    void  *argv;
    struct task_s *next;
	int    id;
} task_t;

//线程任务链表队列
typedef struct task_queue_s {
    task_t  *head;
    task_t **tail;
} task_queue_t;

//线程池
typedef struct thread_pool_s {
	//任务队列,互斥量，事务数量，
    task_queue_t   *queue;
    pthread_mutex_t mtx;
		    
    int   threads;
    int   max_queue;
    char *name;
				    
    zhou_log_t *log;
}





#endif

