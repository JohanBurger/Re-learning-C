cmake_minimum_required(VERSION 3.29)
project(Pointers C)

set(CMAKE_C_STANDARD 11)

add_executable(Pointers main.c
        pointer_operations.h
        pointer_operations.c)
