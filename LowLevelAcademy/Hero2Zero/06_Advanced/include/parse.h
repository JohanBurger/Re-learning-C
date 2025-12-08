#ifndef PARSE_H
#define PARSE_H

typedef struct db_header_t {
    short version;
    short count;
} db_header_t;

int parse_file_header(int fd, int *num_employees);

#endif // PARSE_H
