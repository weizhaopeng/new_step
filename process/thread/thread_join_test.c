#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void *thread1(void *argv);
void *thread2(void *argv);

int main(void) {
	pthread_t th1, th2;
	int 	  ret = 0;
	void 	 *retval1 = NULL, *retval2 = NULL;
	char 	 *string1 = "return_from_thread1", 
			 *string2 = "return_from_thread2";

	ret = pthread_create(&th1, NULL, thread1, string1);
	if (ret != 0) {
		errno = ret;
		perror("thread1 create");
		return -1;
	}

	ret = pthread_create(&th2, NULL, thread2, string2);
	if (ret != 0) {
		errno = ret;
		perror("thread2 create");
		return -1;
	}

	ret = pthread_join(th1, &retval1);
	if (ret != 0){
		puts("thread1 join error");
		return -1;
	}
	printf("retval1 = %s\n", (char *)retval1);

	ret = pthread_join(th2, &retval2);
	if (ret != 0){
		puts("thread2 join error");
		return -1;
	}
	printf("retval2 = %s\n", (char *)retval2);

	return 0;
}

void *thread1(void *argv) {
	printf("now in the thread1\n");
	sleep(5);
	pthread_exit(argv);
}

void *thread2(void *argv) {
	printf("now in the thread2\n");
	sleep(2);
	pthread_exit(argv);
}

	

	

