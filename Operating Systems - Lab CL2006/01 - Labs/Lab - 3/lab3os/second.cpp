#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 10

int main(int argc, char* argv[]) {
    // check if there are enough arguments
    if (argc < SIZE+1) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }
    
    // populate array from command line arguments
    int arr[SIZE] = {};
    for (int i = 0; i < SIZE; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    
    // create child 1
    pid_t child1 = fork();
    if (child1 == 0) {
        // child 1
        std::cout << "I am Child 1 (with ID = " << getpid() << " and Parent's ID = " << getppid() << "): ";
        std::sort(arr, arr + SIZE);
        for (int i = 0; i < SIZE; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        exit(0);
    } else if (child1 > 0) {
        // parent
        wait(NULL);        
        // create child 2
        pid_t child2 = fork();
        if (child2 == 0) {
            // child 2
            std::cout << "I am Child 2 (with ID = " << getpid() << " and Parent's ID = " << getppid() << "): ";
            std::sort(arr, arr + SIZE, std::greater<int>());
            for (int i = 0; i < SIZE; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            exit(0);
        } else if (child2 > 0) {
            // parent
            wait(NULL);
            
            // parent process terminating
            std::cout << "Parent process terminating and my ID = " << getpid() << " and parent's ID = " << getppid() << std::endl;
        } 
        // fork failed
        else {
            std::cerr << "Error: Could not create child 2" << std::endl;
            return 1;
        }
    } 
    // fork failed
    else {
        std::cerr << "Error: Could not create child 1" << std::endl;
        return 1;
    }

    return 0;
}
