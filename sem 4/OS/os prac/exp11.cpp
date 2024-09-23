//code by sneha gupta 2021UCA1859

#include<bits/stdc++.h>
using namespace std;
void bestFit(int blockSize[], int m, int processSize[], int n)
{
   
int allocation[n];
memset(allocation, -1, sizeof(allocation));
// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i=0; i<n; i++)
{
// Find the best fit block for current process
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
// If we could find a block for current process
if (bestIdx != -1)
{
// allocate block j to p[i] process
allocation[i] = bestIdx;
// Reduce available memory in this block.
blockSize[bestIdx] -= processSize[i];
}
}
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main()
{
    int m, n;
    cout<<"Enter the number of blocks: ";
    // 5
    cin>>m;
    cout<<"Enter the number of processes: ";
    // 4
    cin>>n;
int blockSize[m];
int processSize[n];
    cout<<"Enter the block sizes: ";
    // 300 200 600 100 500
    for (int temp=0;temp<m;temp++){
        cin>>blockSize[temp];
    }
    cout<<"Enter the process sizes: ";
    // 212 417 112 426
    for (int temp=0;temp<n;temp++){
        cin>>processSize[temp];
    }
bestFit(blockSize, m, processSize, n);
return 0 ;
}