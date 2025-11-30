#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 10

int main(int argc, char* argv[]) {
    //  less than 10 arguments
    if (argc < SIZE+1) {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }

    // populating array
    int arr[SIZE] ={};
    for(int i=0;i<SIZE;i++)
        arr[i] = atoi(argv[i + 1]);

    pid_t pid = fork();
    if(pid == -1){
        // fork failed
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }
    if (pid == 0) {
        // child process
        std::sort(arr, arr + SIZE);
        std::cout<<"Sorted array is: ";
        for(int i=0;i<SIZE;i++)
            std::cout<<arr[i]<<" ";
        std::cout<<"Child process has finished sorting the array "<<getpid()<<std::endl;
        exit(0);
    }
    else if (pid > 0) {
        // parent process
        wait(NULL);
        std::cout<<"Parent process is now terminating "<<getpid()<<std::endl;
        
        std::cout<<std::endl;
    }
 
    return 0;   
}
