#include <stdio.h>
#include "header.h"
#include <unistd.h>
void main()
{
printf(" I am in main.c \n");
printf("Pid of main.c is %d \n", getpid());
printf(" Calling hello function");
hello();
printf(" Calling add function \n");
add(3,5);
printf(" Back in main.c \n");
}
