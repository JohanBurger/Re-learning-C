#include "print_examples.h"

#include <stdio.h>
#include <stdlib.h>

void print_simple_greeting() {
    printf("Hello, world!\n");
}

void print_greeting(char* first_name, char* last_name, char learning, int age, float some_float) {
    printf("%s %s, %c, age %d, %.1f\n",
        first_name, last_name, learning, age, some_float);
}

void print_asterisks(int width, int height) {
    char* line = malloc(width + 1);
    for (int i = 0; i < width; i++) {
        line[i] = '*';
    }
    line[width] = '\0';
    for (int i = 0; i < height; i++) {
        printf("%s\n", line);
    }
    free(line);
}

void print_numbers_asterisks(int width, int height) {
    char* line = malloc(width + 1);
    for (int line_number = 1; line_number <= height; line_number++) {
        for (int char_number = 0; char_number < width; char_number++) {
            if (char_number + 1<= line_number) {
                line[char_number] = char_number + 1 + '0';
            } else {
                line[char_number] = '*';
            }
            line[width] = '\0';
        }
        printf("%s\n", line);
    }
    free(line);
}
