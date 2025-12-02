#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct employee_t {
    int id;
    int income;
    bool staff;
} employee_t;

typedef enum {
    STATUS_GOOD = 0,
    STATUS_BAD = -1,
} status_t;

/**
 * cat /proc/self/maps displays the memory map of the current process (the cat command itself), showing:
 * 
 * Virtual address ranges for each memory region
 * Permissions (read/write/execute)
 * Offset into the mapped file
 * Device (major:minor numbers)
 * Inode number
 * Pathname of the mapped file or region type
 **/
void show_memory_map(void) {
    FILE *maps = fopen("/proc/self/maps", "r");
    if (maps == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), maps)) {
        printf("%s", line);
    }

    fclose(maps);
}

int initialize_employee(employee_t *employee) {
    // static keyword means the variable is initialized in global scope, 
    // but it is only accessible within this function.
    // Static variables are initialized only once and retain their value between function calls.
    static int employee_count = 0;                  // <- This is in the data segment, not the stack.

    if (employee == NULL) {
        return -1;
    }
    employee_count++;
    employee->id = employee_count;
    employee->income = 0;
    employee->staff = false;
    return employee_count;
}

status_t foo(int **data, size_t size) {
    int *temp = NULL;
    // Dereference **data, so *data is simply a pointer to an int. 
    temp = realloc(*data, size);

    if (temp == NULL) {
        return STATUS_BAD;
    }

    // temp is an int *, and *data is a dereferenced int **, so both are int * types.
    *data = temp;
    return STATUS_GOOD;
}

int main(void) {
    int x = 3;                                      // <- This is on the stack. 
    int *ptr = &x;
    printf("Address of x (value %d): %p\n", *ptr, ptr); 

    employee_t ralph;                               // <- This is also on the stack.
    int ralph_id = initialize_employee(&ralph);
    printf("Address of ralph (%d): %p\n", ralph_id, (void*)&ralph);

    // Dynamic memory allocation. 
    employee_t *tim = malloc(sizeof(employee_t));   // <- This is on the heap. 
    if (tim == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    initialize_employee(tim);
    printf("Address of dynamically allocated employee_t: %p\n", tim);

    show_memory_map();

    free(tim);
    tim = NULL;

    int *first = malloc(64);
    if (first == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    // &first is of type int **, since first is an int *
    // first is a pointer, &first is the address of pointer. 
    if (STATUS_BAD == foo(&first, 128)) {
        fprintf(stderr, "Memory allocation failed in foo()\n");
        free(first);
        first = NULL;
        return EXIT_FAILURE;
    }
    printf("Successfully reallocated memory to 128 bytes at address: %p\n", first);
    free(first);

    return EXIT_SUCCESS;
}
