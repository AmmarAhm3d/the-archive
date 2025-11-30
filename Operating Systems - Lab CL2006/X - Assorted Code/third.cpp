#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    // invalid number of arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <num_processes>" << std::endl;
        return 1;
    }

    int num_processes = atoi(argv[1]);
    // process count must be between 1 and 10
    if (num_processes < 1 || num_processes > 10) {
        std::cerr << "Number of processes must be between 1 and 10" << std::endl;
        return 1;
    }

    pid_t parent_pid = getpid();
    for (int i = 1; i <= num_processes; i++) {
        pid_t ichild = fork();
        if (ichild == -1) {
            std::cerr << "Failed to create child process" << std::endl;
            return 1;
        } else if (ichild == 0) {
            std::cout << "Child " << i << " (with ID = " << getpid() << " and Parent's ID = " << parent_pid << ")" << std::endl;
            break;
        }else if(ichild > 0)
            wait(NULL);
        // at end ith child will be the parent of (i+1)th child 
        parent_pid = getpid();
    }

    // finally parent process will check its own pid with parent_pid,
    // if yes than terminate
    if (getpid() == parent_pid) {
        std::cout << "Parent process is now terminating (with ID = " << getpid() << ")" << std::endl;
    }

    return 0;
}
