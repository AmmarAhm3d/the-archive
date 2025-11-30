#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int fd, fd1;
  fd = open("file.txt", O_RDONLY);
  printf("OLD file descriptor %d\n", fd);
  fd1 = dup2(fd, 1);
  printf("New file descr %d \n", fd1);
}