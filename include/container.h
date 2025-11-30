#pragma once

#include <stddef.h>

typedef struct Vector Vector;

// Wrapper definition for vector_init
Vector* vector_init_impl(size_t element_size);
#define vector_init(TYPE) \
	vector_init_impl(sizeof(TYPE))

// Wrapper definition for append_impl
void append_impl(Vector* v, const void* element);
#define CONCAT2(a, b) a##b
#define CONCAT(a, b) CONCAT2(a, b)

// will be used for appending values stored in variables
#define append(vec, value) \
    append_impl((vec), &(value))

// will be used for appending values directly
#define append_value(type, vec, value)                        \
    do {                                                      \
        type CONCAT(_tmp_, __LINE__) = (value);               \
        append_impl((vec), &CONCAT(_tmp_, __LINE__));         \
    } while (0)


// Wrapper definition for at_impl
void* at_impl(Vector* vector, int pos);
#define at(TYPE, vec, pos) (*(TYPE*)at_impl((vec), (pos)))

void* pop_impl(Vector* vector); // Generic version not implemented yet
#define pop(TYPE, vec) (*(TYPE*)pop_impl((vec)))

void replace_at(Vector* vector, int pos, int value); // Generic version not implemented yet

int length(Vector* vector); // Generic version not implemented yet

// Frees underlying data structure
void vector_free(Vector* vector);
