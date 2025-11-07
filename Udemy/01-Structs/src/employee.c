#include "employee.h"

#include <stdio.h>

void printEmployee(Employee* employee) {
    printf("%s is %d years old and earns $%.2f\n", employee->name, employee->age, employee->salary);
}