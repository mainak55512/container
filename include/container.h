#pragma once

#include <stddef.h>

typedef struct Vector Vector;

// Wrapper definition for vector_init
Vector* vector_init(size_t element_size);
#define vector(TYPE) \
	vector_init(sizeof(TYPE))

// Wrapper definition for append_impl
void append_impl(Vector* v, const void* element);
#define append(TYPE, vec, value) \
	append_impl((vec), &(TYPE){ (value) })

// Wrapper definition for at_impl
void* at_impl(Vector* vector, int pos);
#define at(TYPE, vec, pos) (*(TYPE*)at_impl((vec), (pos)))

void* pop_impl(Vector* vector); // Generic version not implemented yet
#define pop(TYPE, vec) (*(TYPE*)pop_impl((vec)))

void replace_at(Vector* vector, int pos, int value); // Generic version not implemented yet

int length(Vector* vector); // Generic version not implemented yet

// Frees underlying data structure
void free_vector(Vector* vector);
