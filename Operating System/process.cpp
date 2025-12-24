#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

void basic_process_example() {
    std::cout << "Parent process PID: " << getpid() << std::endl;
    
    pid_t pid = fork();
    
    if (pid == -1) {
        std::cerr << "Fork failed!" << std::endl;
        return;
    }
    else if (pid == 0) {
        // Child process
        std::cout << "Child process PID: " << getpid() << std::endl;
        std::cout << "Parent PID: " << getppid() << std::endl;
        exit(0); // Important: child must exit
    }
    else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child to finish
        std::cout << "Child process finished" << std::endl;
    }
}
int main(){
  
}