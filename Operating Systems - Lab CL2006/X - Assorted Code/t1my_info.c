// The second process should print the name, roll number, and your semester number.
// Explain verbally to the instructor the working of the function of execv.
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid  = getpid();
    printf("my_info Program %d\n", getpid());
    char* name = "Ammar";
    char* roll = "20L-0961";
    char* semester = "6";
    printf("Name: %s, Roll: %s, Semester: %s\n", name, roll, semester);

}
