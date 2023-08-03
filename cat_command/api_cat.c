#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>

void read_file(const char *filename, char * buff, size_t _size) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) { 
        perror("Open file failed");
        return;
    }
    int size = read(fd, buff, _size);
    close(fd);
    if (size < 0) { 
        printf("Read file: %d byte\n", size);
    }
}

int main(int argc, char **argv) {
    if (argc < 2)  {
        perror("Usage: input file is invalid");
        return -1;
    }
    char filename[1024];
    char msg[2048];
    memset(filename, 0, sizeof(filename));
    memset(msg, 0, sizeof(msg));
    memcpy(filename, argv[1], sizeof(filename));
    read_file(filename, msg, 2048);
    fprintf(stdout, "\n%s\n", msg);
    return 0;
}