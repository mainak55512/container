# CMake version
cmake_minimum_required(VERSION 4.1.2)

set(CMAKE_C_COMPILER "/usr/bin/clang-18" CACHE PATH "" FORCE)

project(container)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_C_FLAGS "-g")

target_include_directories(${PROJECT_NAME} PRIVATE include)

add_library(container_lib STATIC lib/c_vector.c lib/c_string.c lib/arena.c)

# target_include_directories(container_lib PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE container_lib)
