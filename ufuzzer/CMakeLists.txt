project(ufuzzer_lib)
cmake_minimum_required(VERSION 3.10)


set(SOURCE_FILES
        include/ufuzzer/ufuzzer_api.hpp
        src/fuzzer.cpp
        include/ufuzzer/fuzzer.hpp include/ufuzzer/i_fuzzing_fixture.hpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(ufuzzer ${SOURCE_FILES})
target_link_libraries(ufuzzer ${CONAN_LIBS})