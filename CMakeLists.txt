cmake_minimum_required(VERSION 3.26)
project(lab16 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab16 main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h)
add_subdirectory(libs)
target_link_libraries(lab16 data_structures)