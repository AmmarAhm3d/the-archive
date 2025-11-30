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
	int fd1[2];	//To send data from child1 to parent
	
	pipe(fd1);
	
	int pid1=fork();
	
	if(pid1>0)	//Parent case
	{
		close(fd1[1]);
		
		wait(NULL);
		
		char arr[100];
		
		read(fd1[0], arr, 100);
		
		printf("Received message from child process: %s\n", arr);
		
		int fd2[2];
		if(pipe(fd2)==-1)
			printf("Error in creating pipe2\n");	//To send data from parent to child2
		int pid2=fork();
		
		if(pid2>0)	//Parent case
		{
			close(fd2[0]);
			int size;
			
			for(int i=0; i<strlen(arr); i++)
				if(arr[i]==' ')
					size++;
			size++;
				
			write(fd2[1], &size, sizeof(int));
	
			sleep(1);
			
			write(fd2[1], arr, strlen(arr)+1);
		}
		else if(pid2==0)	//Child case
		{
			close(fd2[1]);
			
			int size=0;
			
			while(read(fd2[0], &size, sizeof(int)) != sizeof(int));
	
			printf("Total number of words received from child are %d\n", size);
			
			while(read(fd2[0], arr, 100) == 0);
			
			char* word=strtok(arr, " ");
			
			float average=0;
			
			average=(average+strlen(word)+1);
			
			while((word=strtok(NULL, " ")) != NULL)
			{
				int wlength=strlen(word);
				while(word[wlength-1]=='.' || word[wlength-1]=='\n')
				{
					word[wlength-1]='\0';
					wlength--;
				}
				
				average=average+strlen(word)+1;
			}
			
			average=(float) (average/size);
			
			printf("Average length of each word is %f\n", average);
		}
		else
		{
			printf("Could not create child2\n");
		}
	}
	else if(pid1 == 0)	//Child case
	{
		close(fd1[0]);
		
		FILE* fp=fopen("data.txt", "r");
		
		char arr[100];
		
		fgets(arr, 100, fp);
		
		write(fd1[1], arr, 100);
		
		exit(0);
	}

	return 0;
}
