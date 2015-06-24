# Define source files in a variable
set(SRCS
  main.c
)

# Add project CFLAGS in a variable
set(ENCODE_CFLAGS "-std=gnu99 -fPIC -Wall -Werror -Wextra -pedantic -Wno-missing-field-initializers -Wno-unused-parameter -Wno-unused-value -Wno-unused-variable")

# Change the CFLAGS
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${ENCODE_CFLAGS})

# Define some options
option(WITH_BZIP2 "Compress output with BZIP2" OFF)
option(WITH_GZIP  "Compress output with GZIP"  OFF)

# Tell cmake to generate an executable
# add_executable(<name> source1 source2 ... sourceN)
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:add_executable
add_executable(encode ${SRCS})

# CMake would build the binary in file bin/src/encode
# Let's make it bin/encode instead
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#variable:PROJECT_BINARY_DIR
set_target_properties(encode PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Define the libraries this project uses

# SSL library is required, we use it to print Base64 on the output
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:find_package
find_package(OpenSSL REQUIRED)

# Print information about the SSL library
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:message
message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

# Add the includes from the SSL library
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:include_directories
include_directories(${OPENSSL_INCLUDE_DIR})

# Link the binary with the SSL library
# http://www.cmake.org/cmake/help/v2.8.12/cmake.html#command:target_link_libraries
target_link_libraries(encode ${OPENSSL_LIBRARIES})

# Is this project configured to use BZIP2?
if (WITH_BZIP2)
  find_package (BZip2)

  # Is there a BZIP2 library in this system?
  if (BZIP2_FOUND)
    # Turn on code that depends on BZip2 library
    add_definitions(-DWITH_BZIP2)
  
    # Print information about the BZIP2 library
    message("BZip2 include dir: ${BZIP2_INCLUDE_DIR}")
    message("BZip2 libraries: ${BZIP2_LIBRARIES}")
  
    # Add the includes and link with the library
    include_directories(${BZIP2_INCLUDE_DIRS})
    target_link_libraries (encode ${BZIP2_LIBRARIES})
  endif (BZIP2_FOUND)
endif (WITH_BZIP2)

# Is this project configured to use Gzip?
if (WITH_GZIP)
    find_package(ZLIB)

    # Is ZLib available in this system?
    if (ZLIB_FOUND)
      # Turn on code that depends on ZLib library
      add_definitions(-DWITH_ZLIB)

      # Print information about the BZIP2 library
      message("ZLIB include dir: ${ZLIB_INCLUDE_DIR}")
      message("ZLIB libraries: ${ZLIB_LIBRARIES}")

      # Add the includes and link with the library
      include_directories(${ZLIB_INCLUDE_DIRS})
      target_link_libraries (encode ${ZLIB_LIBRARIES})
    endif (ZLIB_FOUND)

endif (WITH_GZIP)
