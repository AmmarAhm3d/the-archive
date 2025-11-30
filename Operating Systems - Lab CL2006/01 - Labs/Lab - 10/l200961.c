#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int lap_time;
int num_laps;

void sigchld_handler(int signo) {
    if (signo == SIGCHLD) {
        printf("Received SIGCHLD\n");
        int total_time = lap_time * num_laps;
        printf("Total Time in Seconds: %d\n", total_time);
    }
}

int main() {
    printf("Enter Number of Laps: ");
    scanf("%d", &num_laps);
    printf("Enter Lap Time: ");
    scanf("%d", &lap_time);

    signal(SIGCHLD, sigchld_handler);

    pid_t pid = fork();
    if (pid == 0) {
        for (int i = 1; i <= num_laps; i++) {
            sleep(lap_time);
            printf("Lap: %d Completed\n", i);
        }
        exit(0);
    } else {
        wait(NULL);
    }
    return 0;
}