#include <heap.h>

#define IS_STOP(btnode) (btnode->left == NULL || btnode->left->data < btnode->data || btnode->left->data < btnode->data && btnode->right->data < btnode->data)
//HEAP_MODE	HEAP_DATA_TYPE
void *heap_build(const int capiaity) {
	btree *bt = NULL;

	bt = calloc(1, sizeof(btree));
	if (bt ==  NULL)
		return NULL;
	bt->depth 	 = 0;
	bt->node_num = 0;

	heap *h = NULL;

	h = calloc(1, sizeof(heap));
	if (h == NULL) {
		freee(bt);
		return NULL;
	}
	h->btree 	= bt;
	h->mode  	= HEAP_MODE;
	h->capiaity = capiaity;

	return h;
}
//init the heap with the array
int heap_init(const HEAP_DATA_TYPE *data_set, const int num) {
	
}
//adjust the heap with the new data
int heapify(heap *h, const HEAP_DATA_TYPE in) {

}

//create a new btnode
static inline void *btnode_create(const HEAP_DATA_TYPE in) {
	btnode *node_new = NULL;

	node_new = calloc(1, sizeof(btnode));
	if (node_new == NULL)
		return -1;
	node_new->data  = in;
	node_new->left  = NULL
	node_new->right = NULL;
	return node_new;
}
	
