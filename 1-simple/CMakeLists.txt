# Minimum cmake version that can build this project
# cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]] [FATAL_ERROR])
cmake_minimum_required (VERSION 2.8)

# Name of the project
# project(<projectname> [languageName1 languageName2 ... ] )
# C and C++ assumed by default, if no language is specified
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:project
project (HELLO)

# Tell cmake to generate an executable
# add_executable(<name> source1 source2 ... sourceN)
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:add_executable
add_executable(hello hello.c)
