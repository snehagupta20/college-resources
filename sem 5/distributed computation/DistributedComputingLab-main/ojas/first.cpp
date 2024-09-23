#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

// Define a struct to represent a request message
struct RequestMessage {
 int processId;
};

// Define a struct to represent a reply message
struct ReplyMessage {
 int processId;
};

// Define a class to represent a process
class Process {
private:
 int id;
 vector<RequestMessage> pendingRequests;
 vector<ReplyMessage> receivedReplies;
 bool inCriticalSection = false;

public:
 Process(int id) {
  this->id = id;
 }

  // Declare the processes vector inside the Process class
  static vector<Process> processes;

 // Send a request message to all other processes
 void sendRequest() {
  RequestMessage requestMessage;
  requestMessage.processId = id;

  for (int i = 0; i < processes.size(); i++) {
   if (i != id) {
    processes[i].receiveRequest(requestMessage);
   }
  }
 }

 // Receive a request message from another process
 void receiveRequest(RequestMessage requestMessage) {
  pendingRequests.push_back(requestMessage);

  if (!inCriticalSection) {
   sendReply(requestMessage.processId);
  }
 }

 // Send a reply message to the requesting process
 void sendReply(int requestingProcessId) {
  ReplyMessage replyMessage;
  replyMessage.processId = id;

  processes[requestingProcessId].receiveReply(replyMessage);
 }

 // Receive a reply message from another process
 void receiveReply(ReplyMessage replyMessage) {
  receivedReplies.push_back(replyMessage);

  if (canEnterCriticalSection()) {
   enterCriticalSection();
  }
 }

 // Check if the process can enter the critical section
 bool canEnterCriticalSection() {
  return receivedReplies.size() == processes.size() - 1;
 }

 // Enter the critical section
 void enterCriticalSection() {
  cout << "Process " << id << " is entering the critical section" << endl;

  // Simulate critical section execution
  sleep(1);

  cout << "Process " << id << " is leaving the critical section" << endl;

  inCriticalSection = false;
  pendingRequests.clear();
  receivedReplies.clear();
 }
};

// Define the processes vector outside of the Process class
vector<Process> Process::processes;

int main() {
 // Create three processes

 Process::processes.push_back(Process(0));
 Process::processes.push_back(Process(1));
 Process::processes.push_back(Process(2));

 // Let each process try to enter the critical section
 for (int i = 0; i < Process::processes.size(); i++) {
  Process::processes[i].sendRequest();
 }

 while (true) {
  for (int i = 0; i < Process::processes.size(); i++) {
   if (Process::processes[i].canEnterCriticalSection()) {
    Process::processes[i].enterCriticalSection();
   }
  }
 }

 return 0;
}