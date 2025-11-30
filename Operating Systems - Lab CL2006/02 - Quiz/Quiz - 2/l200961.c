//  Write a C program that creates 2 child processes.
//  First child should get message from user and send it to second child
// using ordinary pipes.
//  Second child should convert it into upper case and parent process
// should print it on screen using ordinary pipes.

// Hint: You can use 2 pipes for Inter process communication.
// Note: You are only allowed to use read(), write() system call for taking input
// or printing output. printf() and scanf() are not allowed.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

#define MSGSIZE 100

int main() {
    char inpbuf[MSGSIZE];
    // two pipes with read and write ends
    int p1[2], p2[2];

    // pipe error handling
    if (pipe(p1) == -1 || pipe(p2) == -1) {
        perror("pipe");
        exit(1);
    }

    // fork error handling
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // First child
        // first pipe and second pipe write end are not needed
        close(p1[0]);
        close(p2[0]);
        close(p2[1]);

        // STDIN_FILENO for reading from stdin
        write(STDOUT_FILENO, "Enter a message: ", 17);
        read(STDIN_FILENO, inpbuf, MSGSIZE);

        // write to first pipe and close it
        write(p1[1], inpbuf, strlen(inpbuf));
        close(p1[1]);
    } else {
        pid = fork();
        // fork error handling
        if (pid == -1) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            // Second child
            // first pipe write end and second pipe read end are not needed
            close(p1[1]);
            close(p2[0]);

            // read from first pipe and convert to uppercase
            read(p1[0], inpbuf, MSGSIZE);
            for (int i = 0; i < strlen(inpbuf); i++) {
                inpbuf[i] = toupper(inpbuf[i]);
            }

            // write to second pipe and close it
            write(p2[1], inpbuf, strlen(inpbuf));
            close(p1[0]);
            close(p2[1]);
        } else {
            // Parent
            // first pipe and second pipe read end are not needed
            close(p1[0]);
            close(p1[1]);
            close(p2[1]);

            // read from second pipe and print to stdout, then close it
            read(p2[0], inpbuf, MSGSIZE);
            write(STDOUT_FILENO, "Received message: ", 18);
            write(STDOUT_FILENO, inpbuf, strlen(inpbuf));

            close(p2[0]);
        }
    }

    return 0;
}
