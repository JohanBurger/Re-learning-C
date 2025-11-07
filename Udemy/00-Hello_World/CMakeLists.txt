cmake_minimum_required(VERSION 3.29)
project(Hello_World
        VERSION 1
        DESCRIPTION "The simplest program one can write."
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(Hello_World
        src/main.c
        src/print_examples.c
        src/print_examples.h)
