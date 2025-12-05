#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	void *data;
	size_t size;
	size_t capacity;
} Arena;

Arena *arena_init(size_t capacity) {
	Arena *arena = (Arena *)malloc(sizeof(Arena));
	void *data = malloc(capacity);
	arena->data = data;
	arena->capacity = capacity;
	arena->size = 0;
	return arena;
}

void *arena_alloc(Arena *arena, size_t size) {
	if (arena->size + size < arena->capacity) {
		void *data = (char *)arena->data + arena->size;
		arena->size += size;
		return data;
	}
	return NULL;
}

void arena_free(Arena *arena) {
	free(arena->data);
	free(arena);
}
