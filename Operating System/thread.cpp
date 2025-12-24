// THIS IS A REAL INTERVIEW QUESTION!
#include <iostream>
#include <thread>
#include <vector>

void printNumbers(int start, int end) {
    for(int i = start; i <= end; i++) {
        std::cout << "Thread " << std::this_thread::get_id() 
                  << ": " << i << std::endl;
    }
}

void interviewQuestion1() {
    std::vector<std::thread> threads;
    
    // Create 3 threads that print different number ranges
    threads.emplace_back(printNumbers, 1, 5);
    threads.emplace_back(printNumbers, 6, 10);
    threads.emplace_back(printNumbers, 11, 15);
    
    for(auto& t : threads) {
        t.join();
    }
}
// Interviewer looks for: thread creation, joining, parameter passing