#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#define BUFFER_SIZE 24
int main() {
  int fd[2];
  int fdtwo[2];
  int i = 0, j = 0, k = 0;
  char filenamesender[BUFFER_SIZE];
  char filenamereceiver[BUFFER_SIZE];
  FILE *fp;
  char c;
  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  if (pipe(fdtwo) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  pid_t pid = fork();
  if (pid == 0) {
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
      printf("Failed to open file.\n");
      return 1;
    }

    while (!feof(fp)) {
      filenamesender[i] = fgetc(fp);
      i++;
    }

    if (write(fd[1], filenamesender, sizeof(filenamesender)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    fclose(fp);
    exit(0);
  } else if (pid > 0) {
    wait(NULL);
    close(fd[1]);
    if (read(fd[0], filenamereceiver, sizeof(filenamereceiver)) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    printf("Received message from child process: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
      if (filenamereceiver[i] == ' ') {
        j++;
      }

      printf("%c", filenamereceiver[i]);
    }
    printf("\n");
    j++;
  }
  pid = fork();
  if (pid == 0) {
   
    if (write(fdtwo[1], &j, sizeof(j)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }
     printf("Total number of words received from child are %d", j);
    exit(0);
  } else if (pid > 0) {
    wait(NULL);
    if (read(fdtwo[0], &k, sizeof(k)) == -1) {

      perror("read");
      exit(EXIT_FAILURE);
    }
    printf("\nAverage length of each word is %f", (float)23 / k);
  }
}


