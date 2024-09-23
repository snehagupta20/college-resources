#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx; // Global mutex object

void criticalSection() {
  // Acquire the lock before entering the critical section
  mtx.lock();

  // Simulate critical section execution
  cout << "Thread " << this_thread::get_id() << " is in the critical section" << endl;

  // Release the lock after exiting the critical section
  mtx.unlock();
}

int main() {
  thread t1(criticalSection);
  thread t2(criticalSection);

  t1.join();
  t2.join();

  return 0;
}