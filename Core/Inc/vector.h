/*
 * vector.h
 *
 *  Implementation of dynamic vector in C using array: If the array is filled, the
 *  addition operation will re-allocate the contents to a larger-size by copying.
 *  @source https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
 */

#ifndef INC_VECTOR_H_
#define INC_VECTOR_H_

#define VECTOR_INIT_CAPACITY 4

typedef struct vector {
	void **items;
	int capacity;
	int total;
} vector;

void vector_init(vector*);
int vector_total(vector*);
//static void vector_resize(vector*, int);
void vector_add(vector*, void*);
void vector_set(vector*, int, void*);
void* vector_get(vector*, int);
void vector_delete(vector*, int);
void vector_free(vector*);

#endif /* INC_VECTOR_H_ */
