#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <io.h>

int read_word(int fd) {
    int ret=0;
    read(fd, (void *) &ret, 4);
    return ret;
}
short read_half(int fd) {
    int ret=0;
    read(fd, (void *) &ret, 2);
    return ret;
}

void write_word(int fd, int word) {
    int val = word;
    write(fd, (void *) &val, 4);
}

void write_half(int fd, short word) {
    int val = word;
    write(fd, (void *) &val, 4);
}