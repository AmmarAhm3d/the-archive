#include <stdio.h>
#include "header.h"
#include <unistd.h>
void hello()
{
printf(" i am in hello.c\n");
printf("Pid of hello.c is %d \n", getpid());
}
