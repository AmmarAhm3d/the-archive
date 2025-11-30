#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define SHM_KEY 9

int main() {
  int shm_id;
  key_t key = SHM_KEY;
  int *shm_ptr;
  int arr[] = {1, 2, 3, 4, 5};
  int arr_size = sizeof(arr)/sizeof(arr[0]);

  // Create shared memory segment
  if ((shm_id = shmget(key, sizeof(int) * arr_size, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach shared memory segment
  if ((shm_ptr = shmat(shm_id, NULL, 0)) == (int *)-1) {
    perror("shmat");
    exit(1);
  }

  // Write integer array to shared memory
  for (int i = 0; i < arr_size; i++) {
    shm_ptr[i] = arr[i];
  }

  // Fork a child process to read integer array from shared memory
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) { // child process
    // Read integer array from shared memory
    printf("Child process read integer array from shared memory: ");
    for (int i = 0; i < arr_size; i++) {
      printf("%d ", shm_ptr[i]);
    }
    printf("\n");

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
