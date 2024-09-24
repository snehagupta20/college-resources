//Google Code Jam 2021 Qualifiers, Problem A

// You are given a list of N integers, indexed from 1 to N. You need to sort this list using a special operation called "Reversort." The Reversort operation works as follows:

// For i from 1 to N-1, do:
// Let j be the position such that the element at position j is the minimum among the elements from positions i to N, inclusive.
// Reverse the sublist from position i to position j.
// The cost of performing the Reversort operation is the length of the sublist being reversed, which is j - i + 1.

// Given a list of integers, your task is to compute the total cost of sorting the list using Reversort.

// Input:
// The first line of the input gives the number of test cases, T.
// For each test case:
// The first line contains an integer N, the number of elements in the list.
// The second line contains N integers, the elements of the list.
// Output:
// For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total cost of sorting the list using Reversort.

// Example:

// Input:
// 3
// 4
// 4 2 1 3
// 2
// 1 2
// 7
// 7 6 5 4 3 2 1

// Output:
// Case #1: 6
// explanation: 
// 4 2 1 3
// i = 0, j = 2
// reverse
// 1 2 4 3 cost = 3
// i = 1, j = 1
// reverse
// 1 2 4 3 cost = 4
// i = 2, j= 3
// reverse
// 1 2 3 4 cost = 6


// Case #2: 1
// Case #3: 12



#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void reverse(vector<int>& list, int start, int end){
    vector<int> ans;
    // cout<<endl<<endl;
    // cout<<"we are now reversing"<<endl;
    if(start>0){
        // cout<<"adding the before elements"<<endl;
        // cout<<"start: "<<start<<endl;
        ans.insert(ans.begin(),list.begin(),list.begin()+start);    
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" "<<endl;
        // }
        // cout<<endl;
    }
    // cout<<"actuall reversing"<<endl;
    for(int i=end;i>=start;i--){
        ans.push_back(list[i]);
    }
    // for(int i=0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    if(end<list.size()-1){
        // cout<<"adding the after elements"<<endl;
        // cout<<"end: "<<end<<endl;
        ans.insert(ans.end(),list.begin()+end+1,list.end());
    }
    
    list=ans;
    return;
}

int reverseSort(vector<int> list){
    // sort the list using reverse sort
    // we have to output the cost

    
    int minIdx = 0;
    int cost=0;
    for(int i=0;i<list.size()-1;i++){
        int minNum =INT_MAX;
        for(int j=i;j<list.size();j++){
            if(minNum>list[j]){
                minNum=list[j];
                minIdx=j;
            }
        }
        // cout<<"min number: "<<minNum<<endl;
        reverse(list, i, minIdx);
        // cout<<"list after reversing"<<endl;
        // for(int i=0;i<list.size();i++){
            // cout<<list[i]<<" ";
        // }
        // cout<<endl;
        cost=cost+(minIdx-i)+1;
        // cout<<"cost: "<<cost<<endl;
    }
    
    return cost;
    

}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> list;
        for(int j=0;j<n;j++){
            int e;
            cin>>e;
            list.push_back(e);
        }
        cout<<reverseSort(list)<<endl;
    }
}