#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define ARRAY_MAX 100
#define RANDOM_LENGTH 20
//array struct
typedef struct {
	uint32_t *set;
	uint32_t cap;
	uint32_t last;
	pthread_rwlock_t rwl;
} array_t;

static inline array_t *array_init(const uint32_t cap);
static inline void 	   array_free(array_t *at);

static inline uint32_t array_index(const uint32_t index, array_t *at);
static inline uint32_t array_get_length(array_t *at);
static inline int 	   array_modify(array_t *at, const uint32_t index, uint32_t new_value);

static inline void  printf_array(array_t *at);
static inline void *fun1(void *argv);
static inline void *fun2(void *argv);
static inline void  array_random(const uint32_t length, array_t *at);

int
main(void) {
	pthread_t th1, th2;
	array_t  *retval1 = NULL, *retval2 = NULL, *at = NULL;

	at = array_init(ARRAY_MAX);
	if (at == NULL) {
		puts("array init failed");
		return -1;
	}
	array_random(RANDOM_LENGTH, at);

	pthread_create(&th1, NULL, fun1, (void*)at);
	pthread_create(&th2, NULL, fun2, (void*)at);

	pthread_join(th1, (void*)&retval1);
	pthread_join(th2, (void*)&retval2);

	printf("parent:\n");
	printf_array(retval2);
	
	array_free(at);
	return(0);
}

//init the array, alloc the memory
static inline array_t *
array_init(const uint32_t cap) {
	array_t *at = NULL;
	int		 ret = 0;

	at = calloc(1, sizeof(array_t));
	if (at == NULL)
		return(NULL);

	at->set = calloc(1, sizeof(uint32_t)*cap);
	if (at == NULL) {
		free(at);
		return(NULL);
	}

	at->cap = cap;
	at->last = 0;
	ret = pthread_rwlock_init(&at->rwl, NULL);
	if (ret != 0) {
		free(at->set);
		free(at);
		return(NULL);
	}

	return(at);
}

//free the memory and destroy the rwlock
static inline void 
array_free(array_t *at) {
	if (at != NULL) {
		if (at->set != NULL) {
			free(at->set); at->set = NULL;
		}
		pthread_rwlock_destroy(&at->rwl);
		free(at); at = NULL;
	}

}

//get the element by the index
static inline uint32_t 
array_index(const uint32_t index, array_t *at) {
	uint32_t retval = 0;

	pthread_rwlock_rdlock(&at->rwl);
	if (index >= at->last) {
		errno = ENOMEM;
		return -1;
	}
	else {
		retval = at->set[index];
		pthread_rwlock_unlock(&at->rwl);
		return(retval);
	}
}

//modify the value by the index
static inline int 
array_modify(array_t *at, const uint32_t index, uint32_t new_value) {
	int retval = 0;

	pthread_rwlock_wrlock(&at->rwl);
	if (index > at->last) {
		errno = ENOMEM;
		retval = -1;
	}
	else {
		at->set[index] = new_value;
		retval = 0;
	}
	pthread_rwlock_unlock(&at->rwl);
	
	return(retval);
}

//get the value length of array
static inline uint32_t 
array_get_length(array_t *at) {
	uint32_t retval = 0;

	pthread_rwlock_rdlock(&at->rwl);
	retval = at->last+1;
	pthread_rwlock_rdlock(&at->rwl);
	
	return(retval);
}

//print all the detail of the array
static inline void 
printf_array(array_t *at) {
	pthread_rwlock_rdlock(&at->rwl);
	printf("the content of the array is :\n");
	for(int i = 0; i <= at->last; i++)
		printf("%d ", at->set[i]);
	printf("\nthe length is:\n");
	printf("%d\n", at->last+1);
	pthread_rwlock_rdlock(&at->rwl);
}

//the thread function 1, 2
static inline void *
fun1(void *argv) {
	array_t *at = (array_t*)argv;

	printf("thread1:\n");
	//printf_array(at);
	array_modify(at, 10, 999);
	sleep(5);

	pthread_exit(argv);
}
	
static inline void *
fun2(void *argv) {
	array_t *at = (array_t*)argv;

	printf("thread2:\n");
	sleep(3);
	printf_array(at);
	//array_modify(at, 9, 988);
	sleep(5);
	pthread_exit(argv);
}

//init the array by random value
static inline void 
array_random(const uint32_t length, array_t *at) {
	pthread_rwlock_wrlock(&at->rwl);

	for (int i = 0; i < length; i++)
		at->set[i] = (uint32_t)random()%20+20;
	at->last = length-1;

	pthread_rwlock_unlock(&at->rwl);
}
