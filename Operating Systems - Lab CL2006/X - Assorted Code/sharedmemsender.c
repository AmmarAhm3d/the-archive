#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 99999

int main() {
    int shm_id;
    key_t key = SHM_KEY;
    int *shm_ptr;

    // Create shared memory segment
    if ((shm_id = shmget(key, sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    if ((shm_ptr = shmat(shm_id, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write integer to shared memory
    *shm_ptr = 37;

    // Detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    exit(0);
}
