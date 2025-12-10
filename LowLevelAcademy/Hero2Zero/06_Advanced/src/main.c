#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "file.h"
#include "parse.h"

int main(int argc, char *argv[]) {
    int num_employees, fd = -1;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <database_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fd = open_file_rw(argv[1]);
    if (fd == -1) {
        return EXIT_FAILURE;
    }

    if (parse_file_header(fd, &num_employees) != 0) {
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    printf("Number of employees: %d\n", num_employees);
    return EXIT_SUCCESS;
}
