#include <container.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
	size_t element_size;
	int capacity;
	int length;
	char *items;
} Vector;

Vector *vector_init_impl(size_t element_size) {
	Vector *vector = (Vector *)malloc(sizeof(Vector));
	vector->items = NULL;
	vector->element_size = element_size;
	vector->capacity = 1;
	vector->length = 0;
	return vector;
}

void append_impl(Vector *vector, const void *element) {
	if (vector->items == NULL) {
		vector->items = (char *)malloc(vector->element_size);
		vector->capacity = 1;
	} else if (vector->length >= vector->capacity) {
		vector->capacity *= 2;
		vector->items = (char *)realloc(
			vector->items, vector->capacity * vector->element_size);
	}
	memcpy((char *)vector->items + (vector->length * vector->element_size),
		   element, vector->element_size);
	vector->length++;
}

void *pop_impl(Vector *vector) {
	if (vector->length > 0) {
		vector->length--;
		return (char *)vector->items + (vector->length * vector->element_size);
	}
	return NULL;
}

void *at_impl(Vector *vector, int pos) {
	if (pos >= 0 && pos < vector->length) {
		return (char *)vector->items + (pos * vector->element_size);
	}
	return NULL;
}

void replace_at_impl(Vector *vector, int pos, const void *value) {
	if (pos >= 0 && pos < vector->length) {
		memcpy((char *)vector->items + (pos * vector->element_size), value,
			   vector->element_size);
	}
}

int length(Vector *vector) { return vector->length; }

void vector_free(Vector *vector) {
	free(vector->items);
	free(vector);
}
