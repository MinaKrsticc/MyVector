# create library " libtools "
add_library (myArray my_array.cpp)
add_library (myString my_string.cpp)
add_library (myVector my_vector.cpp)
# add executable main
add_executable (main main.cpp)
# tell the linker to bind these objects together
target_link_libraries (main myString myArray myVector)

enable_testing()
