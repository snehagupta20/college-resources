#include <iostream>
#include <string>

using namespace std;

class RemoteObject {
public:
    virtual string remoteMethod() = 0;
};

class LocalObject : public RemoteObject {
public:
    string remoteMethod() override {
        return "Hello from the local object!";
    }
};

class Client {
public:
    string callRemoteMethod(RemoteObject* remoteObj) {
        return remoteObj->remoteMethod();
    }
};

int main() {
    LocalObject localObject;
    Client client;

    RemoteObject* remoteObj = &localObject; // Simulate a remote object

    // Invoke the remote method
    string result = client.callRemoteMethod(remoteObj);

    cout << "Result from the remote method: " << result << endl;

    return 0;
}