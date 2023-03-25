/*
 * vector.c
 * Implementation of dynamic vector in C using array
 * @source https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
 */


#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

/* Initializes the vector */
void vector_init(vector* v){
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	v->items = malloc(sizeof(void*) * v->capacity);
}

/* Returns the total no. of current elements in vector */
int vector_total(vector* v){
	return v->total;
}

/* Resizes the vector */
static void vector_resize(vector* v, int capacity){
	void **items = realloc(v->items, sizeof(void *)*capacity);
	if (items){
		v->items = items;
		v->capacity = capacity;
	}
}

/* Increases the capacity of the vector */
void vector_add(vector* v, void* item){
	if (v->capacity == v->total){
		vector_resize(v, v->capacity*2);
	}
	v->items[v->total++] = item;
}

/* Sets an element at the given index */
void vector_set(vector* v, int index, void* item){
	if (index >= 0 && index < v->total){
		v->items[index] = item;
	}
}

/* Gets an element at the given index */
void* vector_get(vector* v, int index){
	if (index >= 0 && index < v->total){
		return v->items[index];
	}
	return NULL;
}

/* Deletes element at the given index */
void vector_delete(vector* v, int index){
	if (index < 0 || index >= v->total){
		return;
	}

	// Deleting the element
	v->items[index] = NULL;

	// Shifting all elements after location "index" by one position to the left
	for (int i = index; i < v->total; i++){
		v->items[i] = v->items[i+1];
		v->items[i+1] = NULL;
	}

	// Decreasing the current number of total elements
	v->total--;

	// Halving the vector's size when total number of current elements is divisible by the capacity
	if (v->total > 0 && v->total == v->capacity / 4){
		vector_resize(v, v->capacity/2);
	}
}


/* Frees the allocated memory */
void vector_free(vector* v){
	free(v->items);
}
