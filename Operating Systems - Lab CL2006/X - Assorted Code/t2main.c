#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3, pid4;
    int status;

    pid1 = fork();

    if (pid1 == 0) {
        // Child process 1: create directory demo_folder
        printf("Child process 1 creating directory demo_folder...\n");
        execlp("mkdir", "mkdir", "demo_folder", NULL);
    }
    else {
         
        wait(NULL);
        sleep(1);

        pid2 = fork();

        if (pid2 == 0) {
            // Child process 2: create files file1.txt and file2.txt
            printf("Child process 2 creating files file1.txt and file2.txt...\n");
            char* args[] = {"touch", "demo_folder/file1.txt", "demo_folder/file2.txt", NULL};
            execvp(args[0], args);
        }
        else {
             
            wait(NULL);
            sleep(1);

            pid3 = fork();

            if (pid3 == 0) {
                // Child process 3: list files in demo_folder
                printf("Child process 3 listing files in demo_folder...\n");
                char* args[] = {"ls", "demo_folder", NULL};
                execvp(args[0], args);
            }
            else {
                 
                wait(NULL);
                sleep(1);

                pid4 = fork();

                if (pid4 == 0) {
                    // Child process 4: remove demo_folder
                    printf("Child process 4 removing directory demo_folder...\n");
                    char* args[] = {"rm", "-rf", "demo_folder", NULL};
                    execvp(args[0], args);
                }
                else {
                     
                    wait(NULL);
                    printf("All child processes have completed.\n");
                }
            }
        }
    }

    return 0;
}
