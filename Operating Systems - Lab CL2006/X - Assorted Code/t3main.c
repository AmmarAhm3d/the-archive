// • Create a program that makes a child and that child replaces itself via execv with another
// program called Fibonacci.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
    pid_t pid = getpid();
    printf("main process %d\n", pid);
    pid_t child = fork();
    if(child == 0){
        // • This Fibonacci program takes a command line argument n.
// • You have to print first n numbers from the Fibonacci series in that new program.
        char *args[] = {"./fibonacci", "10", NULL};
        execv(args[0], args);
    }
    else{
        wait(NULL);
    }
}