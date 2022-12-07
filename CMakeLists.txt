project (MyString) # Mandatory .
cmake_minimum_required (VERSION 3.0) # Mandatory .
set( CMAKE_CXX_STANDARD 11) # Use c ++11.

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
# tell cmake to output binaries here:
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#tell cmake where to look for *.h files
include_directories (${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

