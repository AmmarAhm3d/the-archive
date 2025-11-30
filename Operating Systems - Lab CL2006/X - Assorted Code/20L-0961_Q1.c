#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    char data[500];
    int input_fd = open("input.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("open input.txt");
        return 1;
    }
    int output_fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (output_fd == -1) {
        perror("open output.txt");
        return 1;
    }

    dup2(input_fd, STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);

    int status = read(0, data, 500);
    printf("%s", data);

    close(input_fd);
    close(output_fd);

    return 0;
}
