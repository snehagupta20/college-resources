#include <iostream>
#include <thread>
#include <atomic>
using namespace std; // Add this line to use the std namespace
const int NUM_THREADS = 2;
atomic<int> choosing[NUM_THREADS];
atomic<int> number[NUM_THREADS];
void lock(int thread_id) {
choosing[thread_id] = 1;
number[thread_id] = 1 + (int)number[(1 - thread_id)];
choosing[thread_id] = 0;
for (int other = 0; other < NUM_THREADS; ++other) {
while (choosing[other]) {
// Wait while other thread is choosing its number
}
while (number[other] != 0 && (number[other] < number[thread_id] || (number[other] == number[thread_id] && other < thread_id))) {
// Wait until other threads get their number or have higher priority
}
}
}
void unlock(int thread_id) {
number[thread_id] = 0;
}
void critical_section(int thread_id) {
// Simulate the critical section
cout << "Thread " << thread_id << " is in the critical section." << endl;
}
void thread_function(int thread_id) {
for (int i = 0; i < 5; ++i) {
lock(thread_id);
critical_section(thread_id);
unlock(thread_id);
}
}
int main() {
thread threads[NUM_THREADS];
for (int i = 0; i < NUM_THREADS; ++i) {
threads[i] = thread(thread_function, i);
}
for (int i = 0; i < NUM_THREADS; ++i) {
threads[i].join();
}
Distributed Computing 4
return 0;
}