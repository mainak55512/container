# Simple C Vector Container

This library provides a generic, type-safe dynamic array implementation for C, backed by an **exponentially segmented list** and integrated with an **Arena allocator**. Using C preprocessor macros and compile-time type deduction (`typeof`), it lets you create resizable arrays of any data type (`int`, `char *`, structs, etc.) with **$O(1)$ branchless indexing**, **zero-copy resizing**, and **pointer stability**.

---

## Usage and Features

* **Compile-Time Type Deduction:** Declare typed handles using `Vector(TYPE)` and initialize with `vector_init(arena)`. Functions like `append()`, `at()`, and `pop()` deduce the element type automatically—no need to pass the type into every macro call.
* **Zero-Copy Arena Growth:** Instead of reallocating and copying a single contiguous buffer when full, `Vector` allocates exponentially growing segments ($16, 32, 64\dots$ elements) directly on the arena. Old elements are never moved or copied, leaving zero dead space in your arena.
* **Direct Read/Write via `at()`:** `at(vec, pos)` returns a modifiable lvalue, allowing both reading (`int x = at(vec, 0);`) and direct assignment (`at(vec, 0) = 99;`).
* **Optional Heap Fallback:** Pass an `Arena *` for automatic bulk lifecycle management, or pass `NULL` to allocate segments on the heap and free them with `vector_free(&vec)`.

### Build Steps

You can add the library to your **[flint](https://github.com/mainak55512/flint)** project directly:

```bash
flint add https://github.com/mainak55512/container@v0.2.2

```

Or if you are using CMake, follow the steps below:

1. Clone the repository and navigate to the project folder.
2. Create a build directory:
```bash
mkdir build && cd build

```


3. Generate the build files and compile:
```bash
cmake ..
make

```


This will produce a static library named `libccontainer.a` from the source file `lib/cvector.c`.


**NOTE**: Arena allocator is a pre-requisit for this library, if you are using **flint**, it will be automatically installed as a project dependency, if not grab it from github:

[https://github.com/mainak55512/arena](https://github.com/mainak55512/arena)

---

### Key Functions and Macros

| Function/Macro | Description | C Signature (as seen by user) |
| --- | --- | --- |
| `Vector(TYPE)` | Declares a typed vector pointer for compile-time type checking and deduction. | `Vector(TYPE) vec` |
| `vector_init` | Initializes a new `Vector` backed by the provided `Arena *` (or `NULL` for heap allocation). | `Vector(TYPE) vector_init(Arena *arena)` |
| `append` | Appends a **copy** of `value` to the end of the `Vector`. Automatically deduces the element type. | `void append(Vector(TYPE) vec, TYPE value)` |
| `at` | Accesses the element at `pos` in $O(1)$ time. Returns a **modifiable lvalue** for both reading and direct assignment (`at(vec, 0) = val`). | `TYPE at(Vector(TYPE) vec, int pos)` |
| `pop` | Removes and returns the **last element** of the `Vector`. | `TYPE pop(Vector(TYPE) vec)` |
| `length` | Returns the current number of elements in the `Vector`. | `int length(Vector(TYPE) vec)` |
| `vector_free` | Releases memory associated with the `Vector` when initialized with `NULL` (safe pointer-nulling no-op if backed by an `Arena`). | `void vector_free(Vector(TYPE) *vec)` |

---

## 💡 Example

```c
#include <stdio.h>
#include <arena.h>
#include <container.h>

int main(void) {
    Arena *arena = arena_init(1024);

    // 1. Initialize a typed vector to hold integers
    // Pass `NULL` instead of `arena` if you want to manage memory manually on the heap
    Vector(int) int_vec = vector_init(arena);

    // 2. Append values (type is deduced automatically from int_vec)
    append(int_vec, 10);
    append(int_vec, 20);
    append(int_vec, 30);

    printf("Current Length: %d\n", length(int_vec));         // Output: Current Length: 3

    // 3. Access and modify element at index 0 directly using at()
    printf("Value at index 0: %d\n", at(int_vec, 0));        // Output: 10
    at(int_vec, 0) = 99;
    printf("Value after update: %d\n", at(int_vec, 0));      // Output: 99

    // 4. Pop the last element
    int last_element = pop(int_vec);
    printf("Popped element: %d\n", last_element);            // Output: 30
    printf("New Length: %d\n", length(int_vec));             // Output: 2

    // 5. Free the arena (automatically frees all vectors and segments allocated on it)
    // Note: vector_free(&int_vec) is only needed if initialized with vector_init(NULL)
    arena_free(&arena);

    return 0;
}
```
