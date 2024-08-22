#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct employee {
    char* name;
    int age;
    float salary;
} Employee;

void printEmployee(Employee* employee);

#endif //EMPLOYEE_H
