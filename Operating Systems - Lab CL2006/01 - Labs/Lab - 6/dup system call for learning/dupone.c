#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd1, fd2;
  fd1 = open("file.txt", O_RDONLY);
  fd2 = dup(fd1);
  close(fd1);
  // use fd2 to read from file.txt
  return 0;
}