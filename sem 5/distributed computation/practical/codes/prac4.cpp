#include <iostream>
#include <thread>  // Include for std::thread
#include <mutex>   // Include for std::mutex

std::mutex mtx; // Mutex for locking

void criticalSection(int threadID, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        mtx.lock(); // Acquire the lock
        std::cout << "Thread " << threadID << " is in the critical section (" << i + 1 << "/" << iterations << ")" << std::endl;
        mtx.unlock(); // Release the lock
    }
}

int main() {
    const int numThreads = 3;
    const int iterations = 5;

    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(criticalSection, i, iterations);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}
