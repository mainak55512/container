# CMake version
cmake_minimum_required(VERSION 4.1.2)

set(CMAKE_C_COMPILER "/usr/bin/clang-18" CACHE PATH "" FORCE)


# Project/executable name
project(container)

# kon kon file diye executable compile hobe
add_executable(${PROJECT_NAME} main.c)

# library er header executable e attach korchi karon executable theke library function access korte headers laagbe
target_include_directories(${PROJECT_NAME} PRIVATE include)

add_library(container_lib STATIC lib/container.c)

# target_include_directories(container_lib PRIVATE include)
# shared library ke executable er sathe link korchi
target_link_libraries(${PROJECT_NAME} PRIVATE container_lib)
