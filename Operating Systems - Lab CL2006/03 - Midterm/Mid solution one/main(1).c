#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int pid;
	
	pid = fork();
	if(pid>0)	//Parent case
	{
		wait(NULL);
		
		char* argv[]={"freqvowel", NULL};
		
		execvp("./freqvowel", argv);
	}
	else if(pid == 0)	//Child case
	{
		FILE* fp = fopen("data.txt", "w");
		
		char arr[100]="This is a test message.";
		
		fprintf(fp, "%s", arr);
		
		fclose(fp);
		
		exit(0);
	}

	return 0;
}

