cmake_minimum_required(VERSION 3.16.3)
project(libantenna-test VERSION 0.0.0)

# include_directories(..)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.c" "../src/*.c")

add_executable(test test.c ${SOURCES})
target_link_libraries(test m)

