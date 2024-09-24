#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void reverse(vector<int>& list, int start, int end){
    vector<int> ans;
    if(start>0){
        ans.insert(ans.begin(),list.begin(),list.begin()+start);    
    }
    for(int i=end;i>=start;i--){
        ans.push_back(list[i]);
    }

    if(end<list.size()-1){
        ans.insert(ans.end(),list.begin()+end+1,list.end());
    }
    
    list=ans;
    return;
}

int reverseSort(vector<int> list){

    
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
        reverse(list, i, minIdx);
        cost=cost+(minIdx-i)+1;
    }
    
    return cost;
}


vector<int> reverseEngineer(int n, int c){
    vector<int> arr;
    
    if(c==1){
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }   
        return arr;
    }
    
    for(int i=n;i>=1;i--){
        arr.push_back(i);
    }
    
    int cost = reverseSort(arr);
    if(cost == c){
        return arr;
    }
    vector<int> ans;
    if(cost < c){
        return ans;
    }
    
    int diff = cost - c;
    // they want length diff alredy sorted
    // ek aisa array jisme diff length is alredy sorted, and baki sort karni hai. 
    if(diff > n){
        return ans;
    }
    for(int i=1;i<=diff;i++){
        ans.push_back(i);
    }
    for(int i=n+1;i>=diff;i--){
        ans.push_back(i);
    }
    
    cost = reverseSort(ans);
    cout<<cost;
    return ans;
    
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,c;
        cin>>n>>c;
        vector<int> ans =reverseEngineer(n,c);
        if(ans.size()==0){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// - find max cost that an arr of n length can take
// - min cost that an arr of n length can take
// - cout impossible for that

// how?
// 7 6 5 4 3 2 1 cost = max
// if s > cost
// return impossible

// if cost = 1,
// return 1..N in sorted order


// 5
// 4 6
// 4 3 2 1 
// 2 1
// 51 3 2 1 
// 7 12
// 7 6 5 4 3 2 1 
// 7 2
