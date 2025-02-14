#ifndef POINTEROPERATIONS_H
#define POINTEROPERATIONS_H

#include <stdbool.h>

// void swap(int* a, int*b);
void swap(void* a, void* b, size_t size);
int sum(const int* arr, const size_t size);
bool has_element(const int* arr, const size_t size, const int element);
int get_max(const int* arr, const size_t size);
double get_average(const int* arr, const size_t size);

#endif //POINTEROPERATIONS_H
