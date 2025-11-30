#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {

  pid_t pid;
  pid = fork();

  // printf("Parent pid = %d\n", getpid());
  printf("YOUR QUIZ IS EXPECTED IN NEXT CLASS!\n");
  return 0;
}