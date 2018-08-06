#ifndef _RANDOM_INIT_H_
#define _RANDOM_INIT_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RANDOM_SEED 100

int random_init_set(int *set, int len) {
	if (set == NULL)
		return -1;

	srandom(RANDOM_SEED);
	for (int i = 0; i < len; i++)
		set[i] = random();
	return 0;
}

#endif
