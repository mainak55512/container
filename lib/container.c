#include <stdlib.h>
#include <string.h>

typedef struct {
	size_t element_size;
	int capacity;
	int length;
	char* items;
} Vector;

Vector* vector_init(size_t element_size) {
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	vector->items = NULL;
	vector->element_size = element_size;
	vector->capacity = 0;
	vector->length = 0;
	return vector;
}

void append_impl(Vector* vector, const void* element) {
	if (vector->items == NULL) {
		vector->items = (char*)malloc(vector->element_size);
		vector->capacity = 1;
	} else if (vector->length >= vector->capacity){
		vector->capacity *= 2;
		vector->items = (char*)realloc(vector->items, vector->capacity * vector->element_size);
	}
	// vector->items[vector->length] = element;
	memcpy((char*)vector->items + (vector->length * vector->element_size), element, vector->element_size);
	vector->length++;
}

int pop(Vector* vector) {
	int popped;
	if (vector->length > 0) {
		popped = vector->items[vector->length - 1];
		vector->length--;
	}
	return popped;
}

void* at_impl(Vector* vector, int pos) {
	if (pos >= 0 && pos < vector->length) {
		return vector->items + (pos * vector->element_size);
	}
	return NULL;
}

void replace_at(Vector* vector, int pos, int value) {
	if (pos >= 0 && pos < vector->length) {
		vector->items[pos] = value;
	}
}

int length(Vector* vector) {
	return vector->length;
}

void free_vector(Vector* vector) {
	free(vector->items);
	free(vector);
}
