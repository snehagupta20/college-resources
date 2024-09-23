#include <iostream>
#include <string>

using namespace std;

// Define a remote interface
class RemoteService {
public:
    virtual int add(int a, int b) = 0;
};

// Server implementation
class RemoteServiceImpl : public RemoteService {
public:
    int add(int a, int b) override {
        return a + b;
    }
};

// Client implementation
class RPCClient {
public:
    int callRemoteAdd(int a, int b, RemoteService* service) {
        return service->add(a, b);
    }
};

int main() {
    // Simulate server and client
    RemoteServiceImpl server;
    RPCClient client;

    // The client invokes a remote procedure
    int result = client.callRemoteAdd(5, 3, &server);

    cout << "Result of the remote procedure call: " << result << endl;

    return 0;
}