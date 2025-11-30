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
	
	int vowels[5] = {0};
	
	char temp;
	
	while(fscanf(fp, "%c", &temp)!=EOF)
	{
		if(temp=='a' || temp=='A')
			vowels[0]++;
		else if(temp=='e' || temp=='E')
			vowels[1]++;
		else if(temp=='i' || temp=='I')
			vowels[2]++;
		else if(temp=='o' || temp=='O')
			vowels[3]++;
		else if(temp=='u' || temp=='U')
			vowels[4]++;
	}
	
	printf("Frequency of each vowel: \n");
	printf("a: %d\n", vowels[0]);
	printf("e: %d\n", vowels[1]);
	printf("i: %d\n", vowels[2]);
	printf("o: %d\n", vowels[3]);
	printf("u: %d\n", vowels[4]);
	
	fclose(fp);
	
	char* argv[]={"findsize", NULL};
	
	execvp("./findsize", argv);
	
	return 0;
}
