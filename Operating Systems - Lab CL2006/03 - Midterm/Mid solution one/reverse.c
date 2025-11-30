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
	FILE* fp=fopen("data.txt", "r");
	
	char arr[100];
	char temp;
	
	fgets(arr, 100, fp);
	
	printf("Original message: %s\n\n", arr);
	
	for(int i=0, j=strlen(arr)-1; i<j; i++, j--)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	
	printf("Reversed message:\n%s\n", arr);
	
	fclose(fp);

	return 0;
}
