#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
  int fd[2];
  pid_t pid;
  char message[100], modified[100];
  int i, j, n;
  if (pipe(fd) == -1) {
    fprintf(stderr, "Pipe failed");
    return 1;
  }
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork failed");
    return 1;
  } else if (pid > 0) {
    // parent process
    printf("parent process [id %d]\n", getpid());
    printf("child process    [id %d]\n", pid);
    printf("original string: ");
    fgets(message, 100, stdin);
    close(fd[0]);
    write(fd[1], message, 100);
    close(fd[1]);
    wait(NULL);
  } else {
    // child process
    close(fd[1]);
    read(fd[0], message, 100);
    close(fd[0]);
    n = 0;
    while (message[n] != '\0') {
      if (message[n] >= 'a' && message[n] <= 'z') {
        modified[n] = message[n] - 32;
      } else if (message[n] >= 'A' && message[n] <= 'Z') {
        modified[n] = message[n] + 32;
      } else {
        modified[n] = message[n];
      }
      n++;
    }
    modified[n] = '\0';
    printf("modified string: ");
    printf("%s", modified);
    exit(0);
  }
  
  return 0;
}