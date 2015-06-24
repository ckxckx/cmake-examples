# Minimum cmake version that can build this project
# cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]] [FATAL_ERROR])
cmake_minimum_required (VERSION 2.8)

# Name of the project
# project(<projectname> [languageName1 languageName2 ... ] )
# C and C++ assumed by default, if no language is specified
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:project
project (ENCODE)

# Add support for custom modules
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#variable:CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AddLLVM)

# Add a CMakeLists.txt file in a subdirectory
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:add_subdirectory
add_subdirectory("src")
add_subdirectory("test")
