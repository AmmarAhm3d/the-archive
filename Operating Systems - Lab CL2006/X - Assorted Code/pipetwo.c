#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 5

int main() {
  int pipefd[2];
  pid_t pid;
  int array[ARRAY_SIZE];

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

    for (int i = 0; i < ARRAY_SIZE; i++) {
      array[i] = i + 1;
    }
    if (write(pipefd[1], array, sizeof(array)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    close(pipefd[1]); // Close writing end of the pipe
    _exit(EXIT_SUCCESS);
  } else {            // Parent process
    close(pipefd[1]); // Close writing end of the pipe

    if (read(pipefd[0], array, sizeof(array)) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Received array from child process: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");

    close(pipefd[0]); // Close reading end of the pipe
    exit(EXIT_SUCCESS);
  }
}
