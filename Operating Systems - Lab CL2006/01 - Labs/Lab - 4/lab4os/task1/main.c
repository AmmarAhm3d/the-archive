// Write a C program called main.c and replace it using execv with another program
// named my_info.c.
#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid  = getpid();
    printf("Main Program %d\n", pid);
    char *args[] = {"./my_info", NULL};
    execv(args[0], args);
}