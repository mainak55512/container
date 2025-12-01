# CMake version
cmake_minimum_required(VERSION 4.1.2)

set(CMAKE_C_COMPILER "/usr/bin/clang-18" CACHE PATH "" FORCE)

project(container)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PRIVATE include)

add_library(container_lib STATIC lib/container.c)

# target_include_directories(container_lib PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE container_lib)
