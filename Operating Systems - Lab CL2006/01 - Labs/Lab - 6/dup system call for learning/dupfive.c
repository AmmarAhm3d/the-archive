#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int fd, fd1;
  fd = open("file.txt", O_WRONLY );
  printf("OLD file descriptor %d\n", fd);
  fd1 = dup2(fd, 1);
  printf("New file descriptor %d \n", fd1);
  write(fd1, "This is written to file.txt\n", 28);
  close(fd);
  return 0;
}