#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(void* a, void* b, size_t size) {
    // size_t size = sizeof(a);
    // printf("%zu\n", size);
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
    return (double)sum(arr, size) / (double)size;
}

void input_array(int* array, const size_t size) {
    for (size_t counter = 0; counter < size; counter++) {
        printf("Enter element %zu: ", counter + 1);
        char input[20];
        scanf("%19s", input); // Limits input to 19 characters
        array[counter] = strtol(input, NULL, 10);
    }
}

void print_array(const int* array, const size_t size) {
    for (size_t counter = 0; counter < size; counter++) {
        printf("%d ", array[counter]);
    }
    printf("\n");
}

void get_min_max(const int* arr, const size_t size, int* min, int* max) {
    *min = arr[0];
    *max = arr[0];
    // No need to check the first element again
    for (size_t counter = 1; counter < size; counter++) {
        if (arr[counter] < *min) {
            *min = arr[counter];
        }
        if (arr[counter] > *max) {
            *max = arr[counter];
        }
    }
}

void update_average(const int a, const int b, float* average) {
    *average = (float)(a + b) / 2;
}

bool has_good_neighbor(const int* arr, const size_t size) {
    for (size_t counter = 1; counter < size -1; counter++) {
        int element = arr[counter];
        int before = arr[counter - 1];
        int after = arr[counter + 1];
        if (element == before + after) {
            return true;
        }
    }
    return false;
}

bool check_is_sorted(const int* arr, const size_t size, bool* is_really_sorted) {
    *is_really_sorted = true;
    for (size_t counter = 1; counter < size; counter++) {
        if (arr[counter] < arr[counter - 1]) {
            *is_really_sorted = false;
            return false;
        }
        if (arr[counter] == arr[counter - 1]) {
            *is_really_sorted = false;
        }
    }
    return true;
}

bool check_is_sorted_recursive(const int* arr, const size_t size, bool* is_really_sorted) {
    bool result;

    if (size == 1) {
        *is_really_sorted = true;
        return true;
    }
    result = check_is_sorted_recursive(arr, size - 1, is_really_sorted);
    if (!result || arr[size - 1] < arr[size - 2]) {
        *is_really_sorted = false;
        return false;
    }
    if (arr[size -1 ] == arr[size - 2]) {
        *is_really_sorted = false;
    }
    return result;
}

void reverse_iterative(char *array, const size_t size) {
    for (size_t counter = 0; counter < size / 2; counter++) {
        // printf("%c ", array[counter]);
        printf("%zu: %c %c \n", counter, array[counter], array[size - counter - 1]);
        swap(&array[counter], &array[size - counter - 1], sizeof(char));
        printf("%zu: %c %c \n", counter, array[counter], array[size - counter - 1]);
    }
}