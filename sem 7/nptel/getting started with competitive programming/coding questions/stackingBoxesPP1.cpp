#include <iostream>
#include<stack>
using namespace std;

int stackBoxes(int n){
    stack<int> st;
    int a =0, b=0;
    int ans=0;
    
    
    if(n%2 == 0){
        st.push(n/2);
        st.push(n/2);
        a=n/2;
        b=n/2;
    }
    else{
        st.push((n/2)+1);
        st.push(n/2);
        a=n/2;
        b=(n/2)+1;
    }
    
    ans = ans+ (a*b);
    
    while(!st.empty()){
        int top = st.top();
        if(top == 1){
            st.pop();
            continue;
        }
        top = top/2;        
        if(st.top()%2 ==0){
            st.pop();
            st.push(top);
            st.push(top);
            a=top;
            b=top;
        }
        else{
            st.pop();
            st.push(top+1);
            st.push(top);
            a=top;
            b=top+1;
        }
        ans += a*b;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<stackBoxes(n)<<endl;
    }
    return 0;
}