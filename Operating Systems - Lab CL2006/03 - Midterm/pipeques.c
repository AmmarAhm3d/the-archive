#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {
    //create a pipe
    int pipe1[2];
    int pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    //fork first child process
    pid_t pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid1 == 0) {
        //child1 process: reads a filename, opens the file, and writes its contents to pipe1        
        char filename[BUFFER_SIZE];
        printf("Enter filename: ");
        scanf("%s", filename);

        char message[BUFFER_SIZE];
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "File '%s' not found", filename);
            return 1;
        }
        else {
            while (fgets(message, BUFFER_SIZE, file) != NULL) {
                write(pipe1[WRITE_END], message, strlen(message) + 1);
            }
        }
        fclose(file);
        close(pipe1[WRITE_END]);
        exit(0);
    }
    else {
        //parent process: reads from pipe1, counts number of words, and writes to pipe2
        int word_count = 0;
        close(pipe1[WRITE_END]);
        
        wait(NULL);

        char message[BUFFER_SIZE];
        while (read(pipe1[READ_END], message, BUFFER_SIZE) != 0) {
            char *token = strtok(message, " ");
            while (

