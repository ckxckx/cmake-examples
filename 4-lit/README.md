# Modules + LIT example

This example shows how cmake can use modules to extend its features.  In
particular, it uses a module for LLVM Integrated Tester (LIT).  It also shows
how to use a separate `CMakeLists.txt` file per directory.

## Structure

* **src/main.c**
  * Program that encodes the first argument into several formats:
* **test/**
  * **test_hello.c**
    * Simple hello world test
  * **base64/test_base64.c**
    * Tests the base 64 encoding
  * **bzip2/test_bzip2.c**
    * Tests the base 64 and bzip2 encoding
  * There is no **gzip/test_gzip.c**
    * Exercise for the reader?
* **cmake/AddLLVM.cmake**
  * Module that extends cmake with support for LIT tests

## CMakeLists files

* **CMakeLists.txt**
  * Main file, first one that cmake finds
  * Includes all the others
  * Includes the cmake module
* **src/CMakeLists.txt**
  * Knows how to build the project given the source
* **test/CMakeLists.txt**
  * Knows how to run the tests

## LIT tests

* Run with `lit .`
  * `lit` must be in `$PATH`
    * Clone LLVM repo, find lit in `util/lit/lit.py`
    * Make sure cmake can find lit
      * `ccmake .` and edit `LIT_COMMAND`
      * Set variable `LLVM_MAIN_SRC_DIR` in cmake
      * Add it to the system path so that cmake's `find program` finds it
  * Can be run inside `bin` with `make test-all`
    * Test output dir set by `test/CMakeLists.txt` to `bin/test`
* What is a lit test?
  * Any file that starts with a preamble with LIT instructions
    * **RUN:** Runs the command
      * Test passes if last RUN returns 0
    * **XFAIL** Runs the command, expects it to fail (return !0)
  * Variable substitution
    * `%t1`, `%t2`, ..., `%tN`
      * Temporary files
    * `%T`
      * Directory of `%t`
    * `%s`
      * This test file
    * `%S`
      * The directory of this test file
    * `%{pathsep}`
      * Path separator on this platform
    * `%{your-substituion-here}`
      * Customizable
* **test/lit.cfg**
  * Python file that configures the tests
  * Each file is a test suite
    * There may be many per project, one per different test suite
    * E.g. unit tests, regression tests, etc
  * Can define substitutions
    * E.g. turn `%{cc}` into the compiler used instead of hardcoding gcc on the tests
    * Good idea to do the same for the binaries
      * I say `mkdir bin; cd bin; cmake ..`
      * You say `mkdir build; cd build; cmake ..`
  * Can take parameters from lit with
    * When running lit with `-Dparam=val`
    * Can then be read with `lit_config.params.get('param', None)`
      * Returns `None` if parameter is not defined
    * Useful for test automation with cmake
      * Build/run tests out-of-source
      * Where is the binary?
* lit documentation is not great...
  * http://llvm.org/docs/CommandGuide/lit.html
  * http://llvm.org/docs/TestingGuide.html
