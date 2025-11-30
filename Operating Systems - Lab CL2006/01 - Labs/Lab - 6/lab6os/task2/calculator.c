#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_ELEMENTS 10

int main()
{
    int send_array[MAX_ELEMENTS];
    int recv_array[MAX_ELEMENTS];
    int num_of_elements = MAX_ELEMENTS;
    int size = sizeof(int) * num_of_elements;
    int fd;
    char pipe_name[] = "my_pipe";
    int sum = 0;

    // Open the pipe for reading
    fd = open(pipe_name, O_RDONLY);

    // Receive the array from handler process
    read(fd, send_array, size);
    close(fd);

    // Calculate the sum of the elements in the array
    for (int i = 0; i < num_of_elements; i++) {
        sum += send_array[i];
    }

    // Open the pipe for writing
    fd = open(pipe_name, O_WRONLY);

    // Send the result back to handler process
    recv_array[0] = sum;
    write(fd, recv_array, size);
    close(fd);

    return 0;
}
