#include <bits/stdc++.h> 
using namespace std; 
  
vector<int> luckyArray(vector<int> arr, int n) 
{ 
    vector<int> positive_arr; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] >= 0) 
            positive_arr.push_back(arr[i]); 
    } 
  
    sort(positive_arr.begin(), positive_arr.end()); 
    vector<int> result; 
    for (int window = 1; window <= n; window++) { 
        vector<int> min_list; 
        for (int i = 0; i <= n - window; i++) { 
            int min_element = *min_element(positive_arr.begin() + i, 
                                           positive_arr.begin() + i + window); 
            min_list.push_back(min_element); 
        } 
        result.push_back(*max_element(min_list.begin(), min_list.end())); 
    } 
    reverse(result.begin(), result.end()); 
    return result; 
} 
  
int main() 
{ 
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) 
        cin >> arr[i]; 
  
    vector<int> result = luckyArray(arr, n); 
    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " "; 
  
    return 0; 
} 
