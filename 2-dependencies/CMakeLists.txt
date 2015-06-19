# Minimum cmake version that can build this project
# cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]] [FATAL_ERROR])
cmake_minimum_required (VERSION 2.8)

# Name of the project
# project(<projectname> [languageName1 languageName2 ... ] )
# C and C++ assumed by default, if no language is specified
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:project
project (HELLO)

# Define source files in a variable
set(SRCS
  src/a.c
  src/b.c
  src/c.c
  src/main.c
)

# Add project CFLAGS in a variable
set(HELLO_CFLAGS "-std=gnu99 -fPIC -Wall -Werror -Wextra -pedantic -Wno-missing-field-initializers -Wno-unused-parameter")

# Change the CFLAGS
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${HELLO_CFLAGS})

# Tell cmake to generate an executable
# add_executable(<name> source1 source2 ... sourceN)
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:add_executable
add_executable(hello src/a.c src/b.c src/c.c src/main.c)
