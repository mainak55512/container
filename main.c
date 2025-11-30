#include <container.h>
#include <stdio.h>

int main() {
	Vector* vec = vector(int); // Vector initialized
	Vector* vec_f = vector(float); // Vector initialized

	// Appending values: int
	append(int, vec, 5);
	append(int, vec, 6);

	// Appending values: float
	append(float, vec_f, 2.47);
	append(float, vec_f, 3.47);
	append(float, vec_f, 5.11);

	printf("Length: %d\n", length(vec_f));
	printf("Popped Flt: %f\n", pop(float, vec_f));

	printf("Length: %d\n", length(vec_f));
	printf("Popped Flt: %f\n", pop(float, vec_f));

	printf("Length: %d\n", length(vec_f));
	printf("Popped Flt: %f\n", pop(float, vec_f));

	printf("Popped Int: %d\n", pop(int, vec));
	printf("Length: %d\n", length(vec));

	printf("Popped Int: %d\n", pop(int, vec));
	printf("Length: %d\n", length(vec));

	append(int, vec, 45);
	append(int, vec, 23);
	printf("Length: %d\n", length(vec));
	printf("Int Value: %d\n", at(int, vec, 0));
	printf("Int Value: %d\n", pop(int, vec));
	printf("Int Value: %d\n", pop(int, vec));
	// printf("Int Value: %d\n", pop(int, vec));
	printf("Length: %d\n", length(vec));
	// printf("Float Value: %f\n", at(float, vec_f, 0));

	// Freeing the vector
	free_vector(vec);
	free_vector(vec_f);
}


