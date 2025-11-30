#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
  int pipefd[2];
  pid_t pid;
  char buffer[BUFFER_SIZE];

  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {     // Child process
    close(pipefd[0]); // Close reading end of the pipe

    strcpy(buffer, "Hello, parent process!");
    if (write(pipefd[1], buffer, strlen(buffer) + 1) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    close(pipefd[1]); // Close writing end of the pipe
    _exit(EXIT_SUCCESS);
  } else {            // Parent process
    close(pipefd[1]); // Close writing end of the pipe

    if (read(pipefd[0], buffer, BUFFER_SIZE) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Received message from child process: %s\n", buffer);

    close(pipefd[0]); // Close reading end of the pipe
    exit(EXIT_SUCCESS);
  }
}
