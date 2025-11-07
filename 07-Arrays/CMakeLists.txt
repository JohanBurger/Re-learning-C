cmake_minimum_required(VERSION 3.30)
project(07_Arrays C)

set(CMAKE_C_STANDARD 11)

add_executable(07_Arrays main.c
        array_operations.h
        array_operations.c)
