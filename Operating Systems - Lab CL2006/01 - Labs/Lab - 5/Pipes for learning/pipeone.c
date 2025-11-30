#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pipefd[2];
  // pipefd[0]--> read
  // pipefd[1]--> write
  pid_t pid;
  int valueone;
  int valuetwo;

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

    valueone = 42;
    if (write(pipefd[1], &valueone, sizeof(valueone)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    close(pipefd[1]); // Close writing end of the pipe
    _exit(EXIT_SUCCESS);
  } else {            // Parent process
    close(pipefd[1]); // Close writing end of the pipe

    if (read(pipefd[0], &valuetwo, sizeof(valuetwo)) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    printf("Received value from child process: %d\n", valuetwo);

    close(pipefd[0]); // Close reading end of the pipe
    exit(EXIT_SUCCESS);
  }
}
