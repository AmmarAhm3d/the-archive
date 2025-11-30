#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
    int send_array[] = {1, 5, 7, 2, 15};
    int recv_array[1] = {0}; int NUM_ELEMENTS = 5;
    int size = sizeof(int) * NUM_ELEMENTS;
    int pipe1[2], pipe2[2]; // pipe1 for sending from parent to child, pipe2 for sending from child to parent

    if (pipe(pipe1) == -1) { // create pipe1
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe2) == -1) { // create pipe2
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) { // fork error
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        close(pipe1[1]); // close write end of pipe1
        close(pipe2[0]); // close read end of pipe2

        int sum = 0;
        int i;
        for (i = 0; i < NUM_ELEMENTS; i++) {
            sum += send_array[i];
        }

        write(pipe2[1], &sum, sizeof(int)); // send sum to parent through pipe2

        close(pipe1[0]); // close read end of pipe1
        close(pipe2[1]); // close write end of pipe2
        exit(EXIT_SUCCESS);
    } else { // parent process
        close(pipe1[0]); // close read end of pipe1
        close(pipe2[1]); // close write end of pipe2

        // fix broken pipe error
        if(write(pipe1[1], send_array, size) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        write(pipe1[1], send_array, size); // send array to child through pipe1
        read(pipe2[0], recv_array, sizeof(int)); // read sum from child through pipe2

        printf("Sum Received From Child: %d\n", recv_array[0]);

        close(pipe1[1]); // close write end of pipe1
        close(pipe2[0]); // close read end of pipe2
        exit(EXIT_SUCCESS);
    }
}
