#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SHM_SIZE 1024


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    key_t key = ftok("shmfile",65);
    int shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    char *data = (char*) shmat(shmid,(void*)0,0);

    pid_t pid = fork();
    if (pid == 0) {
        // child process - client
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        char buf[SHM_SIZE];
        ssize_t bytes_read = read(fd, buf, SHM_SIZE);
        if (bytes_read == -1) {
            perror("read");
            exit(1);
        }
        close(fd);

        strncpy(data, buf, SHM_SIZE);
        shmdt(data);
    } else {
        // parent process - server
        wait(NULL);
        int sum = 0;
        int count = 0;
        char *token = strtok(data, " ");
        while (token != NULL) {
            int num = atoi(token);
            sum += num;
            count++;
            token = strtok(NULL, " ");
        }
        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", (float)sum / count);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}