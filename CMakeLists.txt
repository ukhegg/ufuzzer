project(ufuzzer)
cmake_minimum_required(VERSION 3.10)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

if (GCC)
    add_definitions(-Werror)
endif ()

add_subdirectory(ufuzzer)
add_subdirectory(tests)