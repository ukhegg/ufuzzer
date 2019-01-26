project(ufuzzer_tests)
cmake_minimum_required(VERSION 3.10)



set(SOURCE_FILES
        src/main.cpp)

add_executable(ufuzzer_tests ${SOURCE_FILES})
target_link_libraries(ufuzzer_tests ${CONAN_LIBS})