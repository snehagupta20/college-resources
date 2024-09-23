#include<iostream>
#include<map>
#include<vector>
#include<string>
#include <cstdlib>
using namespace std;

void printStr(string mssg){
    for(auto i: mssg){
        cout<<i;
    }
}

void createClient(map<string, int>& val, string name, vector<vector<string> >& messageBuffer){
    int port = (rand() % (9999-1000+1)) + 1000;
    val[name] = port;
    messageBuffer[port].push_back("Buffer Created");
    cout << "Port Assigned: "<<port<<endl;
    return;
}

void broadcast(map<string, int>& val, string message, vector<vector<string> >& messageBuffer){
    for(auto i:val){
        cout<<"Sending Message to: "<<i.first<<" at Port No.: "<<i.second<<" Message: " << message;
        messageBuffer[i.second].push_back(message);
        cout<<"\nBuffer Updated"<<endl;
    }

    return;
}


void cleanup(map<string, int> &ports, vector<vector<string> > &messageBuffer){
    cout<<"Flushing Open Ports..."<<endl;

    ports.clear();
    cout<<"Ports Flushed\n";

    cout<<"Flushing Message Buffer...\n";
    messageBuffer.clear();
    cout<<"Message Buffer Flushed\n";

    return;

}

int main(){
    map<string, int> ports;
    vector<vector<string> > messageBuffer;
    messageBuffer.resize(10000);

    while (1){
        int choice = 0;
        cout<<"\n1. Define New User \n2. Broadcast Message \n3.Target Cast \n4.Cleanup\n";
        cout<<"Enter Your Preference: ";
        cin >> choice;


        if(choice == 4){
            cleanup(ports, messageBuffer);
            break;
        }
        else if(choice == 1){
            string user;
            cout<< "Enter Name: ";
            cin >> user;
            ports[user] = 0;

            createClient(ports, user, messageBuffer);
            continue;
        }else if(choice == 2){
            string mssg;
            cout << "Enter Message: ";
            cin >> mssg;
            broadcast(ports, mssg, messageBuffer);
        }
    }

    return 0;
}