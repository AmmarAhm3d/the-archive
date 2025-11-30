#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(){
pid_t pid = fork();
if(pid < 0){
printf("fork failed\n");
exit(1);
}
if(pid == 0){
FILE* fp = fopen("data.txt", "w");
char *content = "This is a test message.\n";
fwrite(content,sizeof(char),strlen(content),fp);
fclose(fp);
const char* args = {"./freqvowel", "freqvowel", NULL};
execvp(args[0],args);
exit(0);
}
else{
// parent process
wait(NULL);
}
return 0;
}
