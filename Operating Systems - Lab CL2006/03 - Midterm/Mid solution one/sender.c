#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd=open("./makepipe", O_WRONLY);
	
	char arr[]="A computer would deserve to be called intelligent if it could deceive a human into believing it was human\0";
	
	write(fd, arr, sizeof(arr)); 

	return 0;
}
