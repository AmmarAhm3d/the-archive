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
    char *message = "Sometimes it is the people no one imagines anything of who do the things that no one can imagine.\n";

    /* create the named pipe (if it doesn't already exist) */
    mkfifo(PIPE_NAME, 0666);

    /* open the named pipe for writing */
    fd = open(PIPE_NAME, O_WRONLY);

    /* write the message to the named pipe */
    write(fd, message, strlen(message)+1);

    /* close the named pipe */
    close(fd);

    return 0;
}

