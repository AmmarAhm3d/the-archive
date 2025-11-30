#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define pipe_name "fifo"

int main()
{
    int fd;
    char op, buffer[50];
    int operand1, operand2, result;

    // Create the named pipe if it doesn't exist
    // access() returns 0 if the file exists
    if(access(pipe_name, F_OK) == -1) {
        mkfifo(pipe_name, 0666);
    }

    // Open the named pipe for writing
    fd = open(pipe_name, O_WRONLY);

    // Prompt user for input
    printf("Enter operator and two operands (separated by spaces): ");
    scanf("%c %d %d", &op, &operand1, &operand2);

    // Write the data to the named pipe
    sprintf(buffer, "%c %d %d", op, operand1, operand2);
    write(fd, buffer, strlen(buffer)+1);

    // Close the named pipe
    close(fd);

    // Open the named pipe for reading
    fd = open(pipe_name, O_RDONLY);

    // Read the result from the named pipe
    read(fd, &result, sizeof(result));

    // Close the named pipe
    close(fd);

    // Print the result
    printf("Result: %d\n", result);

    // remove pipe
    unlink(pipe_name);
    return 0;
}