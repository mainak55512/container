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

	printf("Int Value: %d\n", at(int, vec, 1));
	printf("Float Value: %f\n", at(float, vec_f, 1));

	// Freeing the vector
	free_vector(vec);
	free_vector(vec_f);
}


