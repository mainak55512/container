#include <container.h>
#include <stdio.h>

typedef struct {
	float x;
	float y;
} Point;

int main() {
	Vector* vec_f = vector_init(float); // Vector initialized, type: Float
	
	// Appending values: float
	append_value(float, vec_f, 2.47); // directly appending value

	float u = 6.779;
	append(vec_f, u); // appending variable value
	
	printf("Float Value: %f\n", at(float, vec_f, 1));
	printf("Popped Float Value: %f\n", pop(float, vec_f));

	Vector* vec = vector_init(Point); // Vector initialization, type: user-defined struct - Point
	Point p = {2.55f, 4.69f};
	append(vec, p);

	printf("Point Value (x): %f\n", at(Point, vec, 0).x);

	printf("Popped Point Value (y): %f\n", pop(Point, vec).y);

	// Freeing the vector
	vector_free(vec);
	vector_free(vec_f);
}


