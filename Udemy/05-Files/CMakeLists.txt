cmake_minimum_required(VERSION 3.29)
project(Files C)

set(CMAKE_C_STANDARD 11)

add_executable(Files main.c
        file_operations.h
        file_operations.c)
