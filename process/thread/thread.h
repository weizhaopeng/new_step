#ifndef _THREAD_H_
#define _THREAD_h_

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//数组加入互斥量
typedef struct array_t {
	int *array;
	int length;
	pthread_mutex_t mutex;
} array_t;

#define LENGTH_ARRAY 20
#endif
