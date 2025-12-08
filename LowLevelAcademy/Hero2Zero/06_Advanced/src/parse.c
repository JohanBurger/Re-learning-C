#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "parse.h"

int parse_file_header(int fd, int *num_employees_out){
    if (fd == -1) {
        fprintf(stderr, "Bad file descriptor provided.\n");
        return fd;
    }

    if (num_employees_out == NULL) {
        fprintf(stderr, "Output parameter for number of employees is NULL.\n");
        return -1;
    }

    db_header_t header = {0};
    ssize_t bytes_read;

    // Retry if the read was interrupted
    do {
        bytes_read = read(fd, &header, sizeof(db_header_t));
    } while (bytes_read == -1 && errno == EINTR);
    
    if (bytes_read != sizeof(db_header_t)) {
        fprintf(stderr, "Failed to read the complete file header.\n");
        return -1;
    }

    *num_employees_out = header.count;
    return 0;
}
