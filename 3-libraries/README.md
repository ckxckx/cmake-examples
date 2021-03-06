# Libraries example

This example shows how cmake can find libraries and can use configure options.

## Structure

* **main.c**
  * Program that encodes the first argument into several formats:
    * *Base64* Non-optional
    * *GZip2 -> Base64* Disabled by default
    * *BZip -> Base64* Disabled by default

# CMake features

* CMake can find packages installed on the setup
  * **find_package**
  * Sets some values automatically:
    * `<package>_FOUND` will be set to indicate whether the package was found
    * `<package>_LIBRARIES` will be set to the path where the package libraries are
    * `<package>_INCLUDES` will be set to the path where the package heades are
* CMake supports build options
  * **option**
  * Use `add_definitions` to pass pre-processor flags to the compiler
    *  ifdef out code that is not used/supported in the current build
