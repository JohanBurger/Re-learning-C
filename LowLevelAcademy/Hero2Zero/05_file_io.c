#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define USE_POSIX

/**
 * By default, we always have 3 file descriptors opened for each process:
 * 0 -> Standard Input (stdin)
 * 1 -> Standard Output (stdout)
 * 2 -> Standard Error (stderr)
 * 
 * A file descriptor is a non-negative integer that uniquely identifies an opened file
 * within a process. File descriptors are used to perform various operations on files,
 * such as reading, writing, and closing files.
 **/

 typedef struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
} database_header_t;

int write_header(char *path, database_header_t *header) {
    if (header == NULL) {
        return EXIT_FAILURE;
    }
#ifdef USE_POSIX
    int fd = open(path, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }
    ssize_t write_size = write(fd, header, sizeof(database_header_t));
    if (write_size != sizeof(database_header_t)) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }
    close(fd);
    return EXIT_SUCCESS;
#else
    // wb - write binary mode
    FILE *file = fopen(path, "wb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    size_t write_size = fwrite(header, 1, sizeof(database_header_t), file);
    if (write_size != sizeof(database_header_t)) {
        perror("fwrite");
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);
    return EXIT_SUCCESS;
#endif
}

int read_header(char *path, database_header_t *header) {
    if (header == NULL) {
        return EXIT_FAILURE;
    }
#ifdef USE_POSIX
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }
    struct stat file_stat = {0};
    if (fstat(fd, &file_stat) != EXIT_SUCCESS) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }
    off_t file_size = file_stat.st_size;
    if (file_size < sizeof(database_header_t)) {
        fprintf(stderr, "File size too small: %lu bytes\n", file_size);
        close(fd);
        return EXIT_FAILURE;
    }
    ssize_t read_size = read(fd, header, sizeof(database_header_t));
    if (read_size != sizeof(database_header_t)) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }
    close(fd);
    if (header->filesize != file_size) {
        fprintf(stderr, "File size mismatch: header %u vs actual %lu\n", 
            header->filesize, file_size);
        return EXIT_FAILURE;
    } else {
        printf("File size verified!\n");
        return EXIT_SUCCESS;
    }
#else
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (file_size < sizeof(database_header_t)) {
        fprintf(stderr, "File size too small: %ld bytes\n", file_size);
        fclose(file);
        return EXIT_FAILURE;
    }
    size_t read_size = fread(header, 1, sizeof(database_header_t), file);
    if (read_size != sizeof(database_header_t)) {
        perror("fread");
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);
    if (header->filesize != file_size) {
        fprintf(stderr, "File size mismatch: header %u vs actual %ld\n", 
            header->filesize, file_size);
        return EXIT_FAILURE;
    } else {
        printf("File size verified!\n");
    }
    return EXIT_SUCCESS;
#endif
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *filename = argv[1];

    short version = 1;
    short employees = 42;
    unsigned int filesize = sizeof(database_header_t);
    database_header_t header_to_write = {
        .version = version,
        .employees = employees,
        .filesize = filesize
    };

    if (write_header(filename, &header_to_write) != EXIT_SUCCESS) {
        fprintf(stderr, "Failed to write header to %s\n", filename);
        return EXIT_FAILURE;
    }   

    database_header_t header_to_read = {0};
    if (read_header(filename, &header_to_read) != EXIT_SUCCESS) {
        fprintf(stderr, "Failed to read header from %s\n", filename);
        return EXIT_FAILURE;
    }

    printf("Database Version: %u, expected %u\n", header_to_read.version, version);
    printf("Number of Employees: %u, expected %u\n", header_to_read.employees, employees);
    printf("File Size: %u bytes, expected %u bytes\n", header_to_read.filesize, filesize);
    return EXIT_SUCCESS;
}
