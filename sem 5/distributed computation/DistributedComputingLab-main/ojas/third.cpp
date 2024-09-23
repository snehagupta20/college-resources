#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int id;
  int waitingFor;
};

vector<Process> processes;

void detectDeadlock(int initiator) {
  int currentProcess = initiator;
  int nextProcess = processes[currentProcess].waitingFor;

  while (nextProcess != initiator) {
    currentProcess = nextProcess;
    nextProcess = processes[currentProcess].waitingFor;
  }

  if (nextProcess == initiator) {
    cout << "Deadlock detected!" << endl;
  } else {
    cout << "No deadlock detected" << endl;
  }
}

int main() {
  // Create three processes and their waiting dependencies
  processes.push_back({0, 2});
  processes.push_back({1, 0});
  processes.push_back({2, 1});

  // Initiate deadlock detection from process 0
  detectDeadlock(0);

  return 0;
}