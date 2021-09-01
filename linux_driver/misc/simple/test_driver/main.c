#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;

    if ((fd = open("/dev/bumper", O_RDONLY)) == -1)
    {
        perror("cannot open the bumper device");
        return -1;
    }

    char buf[1024];
    size_t len = read(fd, buf, 10);
    printf("read ret: %ld\n", len);

    //for this driver not support write function
    len = write(fd, buf, len);
    printf("write ret: %ld, error msg: %s\n", len, strerror(-len));

    return 0;
}
