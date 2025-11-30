#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PIPE_NAME "mypipe"

int main()
{
    char message[256];
    int fd;

    // Open the named pipe for reading
    if ((fd = open(PIPE_NAME, O_RDONLY)) == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the message from the named pipe
    read(fd, message, sizeof(message));

    // Close the named pipe
    close(fd);

    // Reverse the case of each character in the message
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - ('a' - 'A');
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + ('a' - 'A');
        }
    }

    // Open the named pipe for writing
    if ((fd = open(PIPE_NAME, O_WRONLY)) == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the reversed case message to the named pipe
    write(fd, message, strlen(message));

    // Close the named pipe
    close(fd);
    return 0;
}