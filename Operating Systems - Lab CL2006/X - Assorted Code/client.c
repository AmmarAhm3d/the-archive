#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

   int fd = open(argv[1], O_RDONLY);

    char nums[100];

    int r = read(fd, nums,100);

    printf("String: %s" , nums);

    int key = shmget(1200 , 1024 , 0);

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


    strcpy(ptr, nums);

    close(fd);

    shmdt(ptr);


    return 0;
}