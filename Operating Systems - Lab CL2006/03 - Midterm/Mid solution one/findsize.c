#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	FILE* fp=fopen("data.txt", "r");
	
	char temp;
	int size=0;
	
	while(fscanf(fp, "%c", &temp)!=EOF)
		size++;
		
	printf("The size of the message is: %d\n", size);
		
	fclose(fp);
	
	char* argv[]={"reverse", NULL};
	
	execvp("./reverse", argv);

	return 0;
}
