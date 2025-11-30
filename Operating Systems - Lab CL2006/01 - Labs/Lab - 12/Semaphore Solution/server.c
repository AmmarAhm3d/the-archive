#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{

    int key = shmget(1200 , 1024 , IPC_CREAT | IPC_EXCL | 0666);

    if(key < 0)
    {
        printf("SHM GET failed");
        exit(1);
    }

    char* ptr = (char*)shmat(key, NULL, 0);

    if(ptr == NULL)
    {
        printf("SHM ATTACH failed");
        exit(1);
    }

    sleep(10);

    const char sp[2] = " ";

    char* token = strtok(ptr, sp);

    int idx = 0;

    int arr[5];

    for(;token != NULL;)
    {
       
        arr[idx] = atoi(token);
        idx++;
        token = strtok(NULL, sp);
    }

    int sum  = 0;

    for(int i = 0 ; i < 5; i++)
    {
        sum += arr[i];
    }

    double avg  = (double) sum / 5;

    printf("SUM: %d\n" ,sum );
    printf("AVG %f" , avg);

    shmdt(ptr);

    shmctl(key, IPC_RMID, NULL);

    return 0;
}