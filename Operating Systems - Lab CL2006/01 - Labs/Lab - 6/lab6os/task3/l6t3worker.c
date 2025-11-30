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
    char op;
    char buffer[50];
    int operand1;
    int operand2;
    int result;

    // Create the named pipe if it doesn't exist
    // access() returns 0 if the file exists
    if(access(pipe_name, F_OK) == -1) {
        mkfifo(pipe_name, 0666);
    }

    // Open the named pipe for reading
    fd = open(pipe_name, O_RDONLY);

    // Read the data from the named pipe
    read(fd, buffer, sizeof(buffer));

    // Parse the data
    sscanf(buffer, "%c %d %d", &op, &operand1, &operand2);

    // Calculate the result
    switch(op) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator\n");
            exit(1);
    }

    // Close the named pipe for reading
    close(fd);

    // Open the named pipe for writing
    fd = open(pipe_name, O_WRONLY);

    // Write the result to the named pipe
    write(fd, &result, sizeof(result));

    // Close the named pipe for writing
    close(fd);

    return 0;
}