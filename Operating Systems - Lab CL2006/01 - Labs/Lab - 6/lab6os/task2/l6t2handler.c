#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_ELEMENTS 10

int main()
{
    int send_array[MAX_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int recv_array[MAX_ELEMENTS];
    int num_of_elements = MAX_ELEMENTS;
    int size = sizeof(int) * num_of_elements;
    int fd;
    char pipe_name[] = "my_pipe";

    // Create the named pipe
    mkfifo(pipe_name, 0666);

    // Open the pipe for writing
    fd = open(pipe_name, O_WRONLY);

    // Send the array to calculator process
    write(fd, send_array, size);
    close(fd);

    // Open the pipe for reading
    fd = open(pipe_name, O_RDONLY);

    // Receive the result from calculator process
    read(fd, recv_array, size);
    close(fd);

    // Display the result
    printf("Sum of the elements in the array: %d\n", recv_array[0]);

    // Remove the named pipe
    unlink(pipe_name);

    return 0;
}
