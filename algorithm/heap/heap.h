#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdint.h>

#define HEAP_VALUE_TYPE int

typedef struct heap_obj {
	uint32_t		key;
	HEAP_VALUE_TYPE value;
} heap_obj;

typedef struct heap {
	heap_obj *set;
	uint32_t  num;
} heap;

void *heap_build(HEAP_VALUE_TYPE *set, int num);
int   heap_adjust_down(heap *h, int key_n);
int	  heap_adjust_up(heap *h, int key_n);
int	  heap_insert(heap *h, heap_obj *ho);
int	  heap_increase(heap *h, int key_n);
int   heap_delete(heap *h, int key_n);
void *heap_sort(heap *h);
HEAP_VALUE_TYPE heap_get_m(heap *h);
HEAP_VALUE_TYPE heap_cut_m(heap *h);

#endif

