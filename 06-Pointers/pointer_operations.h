#ifndef POINTEROPERATIONS_H
#define POINTEROPERATIONS_H

#include <stdbool.h>

// void swap(int* a, int*b);
void swap(void* a, void* b, size_t size);
int sum(const int* arr, const size_t size);
bool has_element(const int* arr, const size_t size, const int element);
int get_max(const int* arr, const size_t size);
double get_average(const int* arr, const size_t size);
void input_array(const int* array, const size_t size);
void print_array();
void get_min_max(const int* arr, const size_t size, int* min, int* max);
void update_average(const int a, const int b, float* average);
bool has_good_neighbor(const int* arr, const size_t size);
bool check_is_sorted(const int* arr, const size_t size, bool* is_really_sorted);

#endif //POINTEROPERATIONS_H
