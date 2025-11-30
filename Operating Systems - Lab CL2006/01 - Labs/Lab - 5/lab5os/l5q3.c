#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

  // get input and output file names
    char *input_file = argv[1];
    char *output_file = argv[2];

    int fd[2];

    // pipe error handling
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        exit(1);
    }

    pid_t pid = fork();
    // fork error handling
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        exit(1);
    }

    if (pid > 0) { // parent process
        close(fd[READ_END]);
        
        // file handling
        FILE *fp = fopen(input_file, "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open input file\n");
            exit(1);
        }

        fseek(fp, 0L, SEEK_END);
        int size = ftell(fp);
        rewind(fp);

        char *content = (char *)malloc(size + 1);
        fread(content, size, 1, fp);
        content[size] = '\0';
        fclose(fp);

        printf("[PARENT: %d] - Size of Content to Send: %d\n", getpid(), size);
        printf("[PARENT: %d] - Content to send: %s\n\n", getpid(), content);

        write(fd[WRITE_END], &size, sizeof(size));
        write(fd[WRITE_END], content, size);

        close(fd[WRITE_END]);
    } else { // child process
        close(fd[WRITE_END]);

        int size;
        read(fd[READ_END], &size, sizeof(size));

        // prepare content array, size + 1 to store null character
        char *content = (char *)malloc(size + 1);
        read(fd[READ_END], content, size);
        content[size] = '\0';

        printf("[CHILD: %d] - Size of Content to Receive: %d\n", getpid(), size);
        printf("[CHILD: %d] - Content Received: %s\n", getpid(), content);

        // file handling
        FILE *fp = fopen(output_file, "w");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open output file\n");
            exit(1);
        }
        
        fwrite(content, size, 1, fp);
        
        fclose(fp);

        close(fd[READ_END]);
    }

    return 0;
}
