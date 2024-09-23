#include <bits/stdc++.h>
using namespace std;
void FCFS(int arr[], int head, int size)
{
int seek_count = 0;
int distance, cur_track;
for (int i = 0; i < size; i++) {
cur_track = arr[i];
// calculate absolute distance
distance = abs(cur_track - head);
// increase the total count
seek_count += distance;
// accessed track is now new head
head = cur_track;
}
cout << "Total number of seek operations = "
<< seek_count << endl;
// Seek sequence would be the same
// as request array sequence
cout << "Seek Sequence is" << endl;
for (int i = 0; i < size; i++) {
cout << arr[i] << endl;
}
}
int main()
{
    int size;
    cout<<"Enter the number of seek addresses: ";
    // 8
    cin>>size;
    int arr[size];
    cout<<"Enter the addresses: ";
    for (int i=0;i<size;i++){
        cin>>arr[i];
    }
    // 176 79 34 60 92 11 41 114
int head;
    cout<<"Enter the initial head position: ";
    cin>>head;
    // 50
FCFS(arr, head, size);
return 0;
}