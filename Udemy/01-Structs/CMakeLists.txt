cmake_minimum_required(VERSION 3.29)
project(Structs C)

set(CMAKE_C_STANDARD 11)

add_executable(structs src/main.c
        src/employee.h
        src/employee.c)
