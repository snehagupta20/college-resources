//code by sneha gupta 2021UCA1859

#include <bits/stdc++.h>
using namespace std;
void CSCAN(int arr[], int head, int size, int disk_size)
{
int seek_count = 0;
int distance, cur_track;
vector<int> left, right;
vector<int> seek_sequence;
left.push_back(0);
right.push_back(disk_size - 1);
for (int i = 0; i < size; i++) {
if (arr[i] < head)
left.push_back(arr[i]);
if (arr[i] > head)
right.push_back(arr[i]);
}
std::sort(left.begin(), left.end());
std::sort(right.begin(), right.end());
for (int i = 0; i < right.size(); i++) {
cur_track = right[i];
seek_sequence.push_back(cur_track);
distance = abs(cur_track - head);
seek_count += distance;
head = cur_track;
}
head = 0;
seek_count += (disk_size - 1);
for (int i = 0; i < left.size(); i++) {
cur_track = left[i];
seek_sequence.push_back(cur_track);
distance = abs(cur_track - head);
seek_count += distance;
head = cur_track;
}
cout << "Total number of seek operations = "
<< seek_count << endl;
cout << "Seek Sequence is" << endl;
for (int i = 0; i < seek_sequence.size(); i++) {
cout << seek_sequence[i] << endl;
}
}
int main()
{   
    int size;
    cout<<"Enter the number of requests: ";
    cin>>size;
    // 8
    int disk_size;
    cout<<"Enter the disk size: ";
    cin>> disk_size;
    cout<<"Enter the request list: ";
    int arr[size];
    for (int i=0; i<size; i++){
        cin>>arr[i];
    }
// 176 79 34 60 92 11 41 114
int head;
    cout<<"Enter head position: ";
    cin>>head;
    //50
CSCAN(arr, head, size, disk_size);
return 0;
}