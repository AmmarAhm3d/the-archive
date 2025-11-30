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
    ssize_t num_read;

    // Create the named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open the named pipe for writing
    if ((fd = open(PIPE_NAME, O_WRONLY)) == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get input from user
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Write the message to the named pipe
    write(fd, message, strlen(message));

    // Close the named pipe
    close(fd);

    sleep(1);

    // Open the named pipe for reading
    if ((fd = open(PIPE_NAME, O_RDONLY)) == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the message from the named pipe
    num_read = read(fd, message, sizeof(message));

    // Close the named pipe
    close(fd);

    // Print the reversed case message
    for (int i = 0; i < num_read; i++)
    {
        printf("%c", message[i]);
    }
    printf("\n");

    // Remove the named pipe
    unlink(PIPE_NAME);

    return 0;
}
