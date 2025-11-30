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
	int fd=open("./makepipe", O_RDONLY);
	
	char arr[200];
	
	read(fd, arr, 200);
	printf("%s\n", arr);
	
	int fr[7]={0};
	char* word=strtok(arr, " ");
	
	if(strcmp(word, "a")==0)
		fr[0]++;
	else if(strcmp(word, "an") == 0)
		fr[1]++;
	else if(strcmp(word, "the") == 0)
		fr[2]++;
	else if(strcmp(word, "of") == 0)
		fr[3]++;
	else if(strcmp(word, "to") == 0)
		fr[4]++;
	else if(strcmp(word, "in") == 0)
		fr[5]++;
	else if(strcmp(word, "and") == 0)
		fr[6]++;					
		
	while((word=strtok(NULL, " "))!=NULL)
		if(strcmp(word, "a")==0)
		fr[0]++;
	else if(strcmp(word, "an") == 0)
		fr[1]++;
	else if(strcmp(word, "the") == 0)
		fr[2]++;
	else if(strcmp(word, "of") == 0)
		fr[3]++;
	else if(strcmp(word, "to") == 0)
		fr[4]++;
	else if(strcmp(word, "in") == 0)
		fr[5]++;
	else if(strcmp(word, "and") == 0)
		fr[6]++;					
		
	printf("Stop Words Frequencies:\n");
	printf("a: %d\n", fr[0]);
	printf("an: %d\n", fr[1]);
	printf("the: %d\n", fr[2]);
	printf("of: %d\n", fr[3]);
	printf("to: %d\n", fr[4]);
	printf("in: %d\n", fr[5]);
	printf("and: %d\n", fr[6]);

	return 0;
}
