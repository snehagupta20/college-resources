#include <iostream>
#include <vector>

using namespace std;

class Client {
private:
  string name;

public:
  Client(string name) {
    this->name = name;
  }

  string getName() {
    return name;
  }
};

vector<Client> clients;

void broadcastMessage(string message) {
  for (Client& client : clients) {
    cout << "Sending message to " << client.getName() << ": " << message << endl;
  }
}

int main() {
  // Add some clients to the chat
  clients.push_back(Client("Alice"));
  clients.push_back(Client("Bob"));
  clients.push_back(Client("Charlie"));

  // Simulate receiving messages from clients and broadcasting them
  broadcastMessage("Hello from Alice!");
  broadcastMessage("Hi there, from Bob!");
  broadcastMessage("Greetings everyone, Charlie here!");

  return 0;
}