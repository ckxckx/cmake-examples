# Where is the LLVM?
# set(LLVM_MAIN_SRC_DIR "/path/to/llvm")

# Use targets defined in the custom module

if (WITH_BZIP2)
  add_lit_testsuite(test-all "Run the bzip2 tests"
    ${CMAKE_CURRENT_SOURCE_DIR}/bzip2
    PARAMS
      test_dir=${CMAKE_CURRENT_BINARY_DIR}
      encode_binary="${PROJECT_BINARY_DIR}/encode"
      )
else (WITH_BZIP2)
  add_lit_testsuite(test-all "Run the base64 tests"
    ${CMAKE_CURRENT_SOURCE_DIR}/base64
    PARAMS
      test_dir=${CMAKE_CURRENT_BINARY_DIR}
      encode_binary="${PROJECT_BINARY_DIR}/encode"
    )
endif (WITH_BZIP2)
