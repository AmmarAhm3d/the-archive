#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "story_pipe";

    mkfifo(myfifo, 0666);
   

    return 0;
}

