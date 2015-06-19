# Dependencies example

This example shows how cmake scans the sources for dependencies automatically.

## Structure

* **a.[ch]**
  * Function `a` that returns the string `Hello`
* **b.[ch]**
  * Function `b` that returns concats the result of `a` with `, world`
* **c.[ch]**
  * Function `c` that returns concats the result of `b` with `!`
* **main.[ch]**
  * Function `main` with the entry point that prints the result of `c`

## Partial builds using the dependency information

* Use a non-trivial change that modifies the structure of the object file
  * Add a function to each file
  * Change the prototype of the function that each file defines
* Change `main.c`
  * Only re-compiles `main.c`
* Change `c.c` 
  * Recompiles `c.c` and `main.c`
* Change `b.c` 
  * Recompiles `b,c`, `c.c`, and `main.c`
* Change `a.c` 
  * Recompiles `a.c`, `b,c`, `c.c`, and `main.c`

# Other things this example shows

* **Variables**
  * All the sources in the CMakeLists.txt file are defined inside variable `SRCS`
* **CFLAGS**
  * The flags passed to the C compiler when compiling are defined by variable `CMAKE_C_FLAGS`
  * Define the CFLAGS local to this project in variable `HELLO_CFLAGS`
  * Avoid clobbering when defining the `CMAKE_C_FLAGS`
