#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class assembler{
    private:
    unordered_map<string, string> symbolTable;
    unordered_map<string, string> exsistAdd;

    public:
    void addSymbol(string s, string code){
        if(exsistAdd.count(code)==0){
            exsistAdd[code] = s;
            symbolTable[s] = code;
        }
        else{
            cout<<"This address is already given to "<<exsistAdd[code]<<endl;
        }
    }

    void retrieve(string s){
        if(symbolTable.count(s)==0){
            cout<<"This isnt a defined instruction"<<endl;
        }
        else{
            cout<<symbolTable[s]<<endl;
        }
    }
};

string disect(string s){
    int i = 0;
    string ans = "";
    while(i<s.size() && s[i]!=' '){
        ans += s[i];
        i++;
    }
    return ans;
}

int main(){
    assembler A;
    int x = 1;
    while(x){
        cout<<"What is your task?"<<endl;
        cout<<"1. Add instructions to the assembler."<<endl;
        cout<<"2. Add your code."<<endl;
        cout<<"3. End"<<endl;
        int in;
        cin>>in;
        if(in==1){
            cout<<"Enter the symbol"<<endl;
            string symbol;
            cin>>symbol;
            cout<<"Enter Hex code"<<endl;
            string code;
            cin>>code;
            A.addSymbol(symbol, code);
        }
        if(in==2){
            cout<<"Enter instruction: "<<endl;
            string s;
            cin>>s;
            A.retrieve(disect(s));
        }
        if(in==3){
            cout<<"BYE";
            x = 0;
        }
    }

    return 0;
}