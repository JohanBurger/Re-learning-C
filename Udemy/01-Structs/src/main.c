#include "employee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    Employee employee0;
    puts("Enter first employee's name:");
    scanf("%ms", &employee0.name);

    puts("Enter first employee's age:");
    scanf("%d", &employee0.age);

    puts("Enter first employee's salary:");
    scanf("%f", &employee0.salary);

    strcpy(employee0.name, "Gob Bluth");

    Employee* employee1 = malloc(sizeof(Employee));
    puts("Enter second employee's name:");
    scanf("%s", employee1->name);

    puts("Enter second employee's age:");
    scanf("%d", &employee1->age);

    puts("Enter second employee's salary:");
    scanf("%f", &employee1->salary);

    Employee employee2 = {"Buster Bluth", 32, 40000.0f};
    Employee employee3 = {.age = 16, .name = "Lindsay Bluth"};

    Employee** employees = calloc(5, sizeof(Employee));
    employees[0] = &employee0;
    employees[1] = employee1;
    employees[2] = &employee2;
    employees[3] = &employee3;

    for(int counter = 0; counter <= 5; counter++) {
        Employee* employee = employees[counter];
        if (employee) {
            printEmployee(employees[counter]);
        } else {
            puts("D'OH!");
        }
    }

    free(employee1);
    free(employees);

    return 0;
}
