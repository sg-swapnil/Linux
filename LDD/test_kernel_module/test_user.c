#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;
    char read_buf[256];
    const char *msg = "Hello from user space!";

    fd = open("/dev/testmod", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (write(fd, msg, strlen(msg)) < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    printf("User wrote: %s\n", msg);

    lseek(fd, 0, SEEK_SET);
    int bytes = read(fd, read_buf, sizeof(read_buf) - 1);
    if (bytes >= 0) {
        read_buf[bytes] = '\0';
        printf("User read: %s\n", read_buf);
    } else {
        perror("read");
    }

    close(fd);
    return 0;
}

