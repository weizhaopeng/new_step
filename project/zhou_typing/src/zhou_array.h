#ifndef _ZHOU_ARRAY_INCLUDE_
#define _ZHOU_ARRAY_INCLUDE_

#include "zhou.h"
#include "zhou_config.h"

#define ZHOU_ARRAY_CAPACITY_INIT 1024

typedef struct {
	zhou_void set;
	zhou_uint last;
	zhou_uint max;
} zhou_array;

zhou_array* zhou_array_create(const zhou_int capacity);
zhou_array* zhou_array_extend(zhou_array *old);
zhou_array* zhou_array_destroy(zhou_array *ay);

#endif

