#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_KEY 99999
#define SHM_SIZE 100

int main() {
  int shm_id;
  key_t key = SHM_KEY;
  char *shm_ptr;
  char str[] = "Hello, world!";

  // Create shared memory segment
  if ((shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach shared memory segment
  if ((shm_ptr = shmat(shm_id, NULL, 0)) == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  // Write string to shared memory
  strncpy(shm_ptr, str, SHM_SIZE);

  // Fork a child process to read string from shared memory
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) { // child process
    // Read string from shared memory
    char buffer[SHM_SIZE];
    strncpy(buffer, shm_ptr, SHM_SIZE);
    printf("Child process read string: %s\n", buffer);

    // Detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      exit(1);
    }

    exit(0);
  } else { // parent process
    wait(NULL);

    // Detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }

    exit(0);
  }
}
