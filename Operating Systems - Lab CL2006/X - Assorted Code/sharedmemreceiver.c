#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>

#define SHM_KEY 99999

int main() {
    int shm_id;
    key_t key = SHM_KEY;
    int *shm_ptr;

    // Create shared memory segment
    if ((shm_id = shmget(key, sizeof(int), 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    if ((shm_ptr = shmat(shm_id, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read integer from shared memory
    int num = *shm_ptr;
    printf("Read integer %d from shared memory.\n", num);

    // Check whether the number is prime
    int is_prime = 1;
    if (num <= 1) {
        is_prime = 0;
    } else {
        for (int i = 2; i <= num/2; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    // Print whether the number is prime or not
    if (is_prime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

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
