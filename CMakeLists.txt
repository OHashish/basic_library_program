cmake_minimum_required(VERSION 2.8)

project(library)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

include_directories(unity/include)

add_executable(library main.c interface.c book_management.c library.c users.c)

add_executable(unit_tests unit_tests.c book_management.c library.c users.c unity/src/unity.c)

install(TARGETS library RUNTIME DESTINATION bin)
