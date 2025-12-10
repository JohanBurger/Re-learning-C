#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#include "file.h"

int open_file_rw(const char *path) {
    int fd = open(path, O_RDWR);
    if (fd == -1) {
        perror("open");
    }
    return fd;
}
