#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE_NAME "my_pipe"

int main()
{
    int fd;
    char message[100];

    /* open the named pipe for reading */
    fd = open(PIPE_NAME, O_RDONLY);

    /* read the message from the named pipe */
    read(fd, message, 100);

    /* display the message */
    printf("Received message: %s", message);

    /* close the named pipe */
    close(fd);

    /* remove the named pipe */
    unlink(PIPE_NAME);

    return 0;
}

