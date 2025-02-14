#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(void* a, void* b, const size_t size) {
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int sum(const int* arr, const size_t size) {
    if (size <= 0) {
        return -1;
    }
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

bool has_element(const int* arr, const size_t size, const int element) {
    if (size <= 0) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

int get_max(const int* arr, const size_t size) {
    if (size <= 0) {
        return -1;
    }

    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double get_average(const int* arr, const size_t size) {
    if (size <= 0) {
        return -1;
    }
    return (double)sum(arr, size) / size;
}