add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(
	${TEST_BINARY}
	my_string_test.cpp
	my_array_test.cpp
	my_vector_test.cpp
)
 target_link_libraries(${TEST_BINARY}
   myString
   myArray
   myVector
   gtest gtest_main
 )
 add_test(
	  NAME ${TEST_BINARY}
	  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})
