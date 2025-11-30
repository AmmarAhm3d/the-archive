#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int lap_time = atoi(argv[1]); // Lap time in seconds
    int num_laps = atoi(argv[2]); // Number of laps

    pid_t pid;
    int status;

    // Total time calculator process
    // child process
    if ((pid = fork()) == 0) {
        int total_time = 0;
        while (1) {
            sleep(1);
            total_time++;
            if (total_time == num_laps * lap_time) {
                printf("Total time: %d seconds\n", total_time);
                exit(0);
            }
        }
    }
    // Lap time calculator process
    // parent process
    else {
        int lap_counter = 1;
        int lap_time_counter = 0;
        while (1) {
            sleep(1);
            lap_time_counter++;
            if (lap_time_counter == lap_time) {
                printf("Lap %d: %d seconds\n", lap_counter, lap_time_counter);
                lap_counter++;
                lap_time_counter = 0;
                if (lap_counter > num_laps) {
                    waitpid(pid, &status, 0);
                    exit(0);
                }
            }
        }
    }

    return 0;
}
