#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int input_fd, output_fd;

    // open input file
    input_fd = open("input.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("Failed to open input file");
        exit(1);
    }

    // open output file
    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (output_fd == -1) {
        perror("Failed to open output file");
        exit(1);
    }

    // duplicate input file descriptor to stdin
    if (dup2(input_fd, STDIN_FILENO) == -1) {
        perror("Failed to redirect stdin");
        exit(1);
    }

    // duplicate output file descriptor to stdout
    if (dup2(output_fd, STDOUT_FILENO) == -1) {
        perror("Failed to redirect stdout");
        exit(1);
    }

    // close input and output file descriptors
    close(input_fd);
    close(output_fd);

    // execute cat command
    execlp("cat", "cat", NULL);

    return 0;
}
