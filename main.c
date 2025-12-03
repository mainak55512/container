#include <container.h>
#include <stdio.h>

typedef struct {
	float x;
	float y;
} Point;

int main() {
	Vector* vec = vector_init(Point); // Vector initialization, type: user-defined struct - Point

	Point p = {2.55f, 4.69f};
	append(Point, vec, p);
	append(Point, vec, ((Point){3.33f, 4.44f}));

	printf("Point Value (x): %f\n", at(Point, vec, 0).x);

	Vector* vec_f = vector_init(float); // Vector initialized, type: Float
	
	// Appending values: float
	float u = 6.779;
	append(float, vec_f, u); // appending variable value
	append(float, vec_f, 2.47); // directly appending value
	
	printf("Float Value: %f\n", at(float, vec_f, 1));

	// Replace a value at a position
	float u1 = 2.2222f;
	replace_at(float, vec_f, 1, u1);

	printf("Float Value: %f\n", at(float, vec_f, 1));

	// Freeing the vector
	vector_free(vec);
	vector_free(vec_f);

	String* st1 = string_from("Mainak ");
	String* st2 = string_from("Bhattacharjee");
	String* newStr = string_concat(st1, st2);
	printf("\nString: %s", string(newStr));

	string_free(st1);
	string_free(st2);
	string_free(newStr);
	// printf("\nString length: %d", string_len(st));
}


