#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {

  int res, n;
  res = open("fifo1", O_WRONLY);
  write(res, "Message", 7);
  printf("Sender process having PID %d sent the data \n", getpid());
}