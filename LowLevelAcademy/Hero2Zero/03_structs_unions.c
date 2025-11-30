#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Structs: A block of memory that can hold multiple related variables of different types.
 * 
 * With **typedef struct**, you can use the type name directly without the struct keyword, 
 * resulting in more concise and idiomatic code. 
 * 
 * The tag name `struct employee_t` is visible immediately inside the struct definition, 
 * while the typedef name employee_t only becomes available after the closing brace. 
 * This is essential for pointers to the same type (linked lists, trees, etc.).
 * 
 * __attribute__((__packed__)) tells the compiler not to add any padding between members.
 * This prevents the compiler from aligning data members to certain byte boundaries,
 * which can cause interoperability issues with data formats that expect a specific layout.
 **/
typedef struct employee_t {
    int id;
    char first_name[64];
    char last_name[64];
    float income;
    bool is_manager;
}__attribute__((__packed__)) employee_t;

/**
 * Unions: A block of memory that can hold different types but only one at a time. 
 * Enough memory is allocated to hold the largest member.
 **/
typedef union data_u {
    int x;
    char c;
    short s;
} data_u;

int main(void) {
    size_t size = sizeof(employee_t);
    printf("The size of employee_t is %zu bytes.\n", size);

    employee_t fred = {
        .first_name = "Fred",
        .last_name = "Flintstone",
        .income = 100.00f,
        .is_manager = true
    };

    char *managerial = fred.is_manager ? "is" : "is not";

    printf("%s %s earns $%.2f / hour. He %s a manager.\n", 
        fred.first_name, fred.last_name, fred.income, managerial);

    data_u value;
    value.x = 0x41424344;
    printf("0x%x, 0x%hx 0x%hhx\n", value.x, value.s, value.c); // Outputs: 0x41424344 0x4344 0x44

    return EXIT_SUCCESS;
}
