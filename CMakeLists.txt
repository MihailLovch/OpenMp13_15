cmake_minimum_required(VERSION 3.26)
project(13_15)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

add_executable(Task3
        task15.cpp)

target_compile_options(Task3 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task3 PRIVATE ${OpenMP_CXX_FLAGS})