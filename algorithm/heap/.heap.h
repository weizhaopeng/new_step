#ifndef _HEAP_H_
#define _HEAP_H_

/*heap is a structure built by total 2-tree with the parent is always
 *larger than the child node
 *the speciiality of it is the heap store the max or min k num of the 
 *order. the k is the tree's node 
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define HEAP_DATA_TYPE int
//1:low_root 0:high_root
#define HEAP_MODE 	   1	

typedef struct btnode {//2-tree node
	HEAP_DATA_TYPE data;
	struct btnode *left;
	struct btnode *right;
} btnode;

typedef struct btree {//the 2-tree
	btnode  *root;
	uint32_t depth;
	uint64_t node_num;
} btree;

typedef struct heap {//heap
	btree   *bt;
	char     mode;
	uint64_t capiaity;
};
	
void *heap_build(const int capiaity);	//build the heap
void *heapify	(void *data);			//insert the new data

#endif

