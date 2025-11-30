#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  pid_t p, cpid;
  printf("main id %d\n", getpid());
  printf("before fork\n");
  p = fork();
  if (p == 0) {
    printf("I am child having id %d\n", getpid());
    printf("My parent's id is %d\n", getppid());

  } else if (p > 0) {
    printf("My child's id is %d\n", p);
    printf("I am parent having id %d\n", getpid());
  } else {
    printf("ERROR");
  }
  printf("Your quiz is expected in next class\n");
}