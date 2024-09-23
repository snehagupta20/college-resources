#include <iostream>

using namespace std;

class Process {
private:
  int id;
  int logicalClock;

public:
  Process(int id) {
    this->id = id;
    this->logicalClock = 0;
  }

  void incrementLogicalClock() {
    logicalClock++;
  }

  void sendMessage(Process& receiver, int eventId) {
    logicalClock++;
    cout << "Process " << id << " sending message with event id " << eventId << " and logical clock " << logicalClock << endl;
    receiver.receiveMessage(*this, eventId);
  }

  void receiveMessage(Process& sender, int eventId) {
    logicalClock = max(logicalClock, sender.logicalClock) + 1;
    cout << "Process " << id << " received message with event id " << eventId << " and updated logical clock to " << logicalClock << endl;
  }
};

int main() {
  Process p1(1);
  Process p2(2);

  p1.sendMessage(p2, 1);
  p2.sendMessage(p1, 2);
  p1.sendMessage(p2, 3);

  return 0;
}