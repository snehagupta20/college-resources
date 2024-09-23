#include<iostream>
using namespace std;
void findWaitingTime(int processes[], int n,
int bt[], int wt[], int quantum)
{
int rem_bt[n]; // array of remaining times
for (int i = 0 ; i < n ; i++)
rem_bt[i] = bt[i];
int t = 0; // current time
while (1) // traversing
{
bool done = true;
for (int i = 0 ; i < n; i++)
        {
if (rem_bt[i] > 0)
{
done = false; // There is a pending process
if (rem_bt[i] > quantum)
{
// how much time a process has been processed
t += quantum;
// Decrease the burst_time of current process
rem_bt[i] -= quantum;
}
else
{
// how much time a process has been processed
t = t + rem_bt[i];
wt[i] = t - bt[i];
rem_bt[i] = 0;
}
}
}
if (done == true)
break;
}
}
void findTurnAroundTime(int processes[], int n,
int bt[], int wt[], int tat[])
{
// calculating turnaround time by adding
// bt[i] + wt[i]
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[],
int quantum)
{
int wt[n], tat[n], total_wt = 0, total_tat = 0;
findWaitingTime(processes, n, bt, wt, quantum);
findTurnAroundTime(processes, n, bt, wt, tat);
cout << "Processes "<< " Burst time "
<< " Waiting time " << " Turn around time\n";
for (int i=0; i<n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
<< wt[i] <<"\t\t " << tat[i] <<endl;
}
cout << "Average waiting time = "
<< (float)total_wt / (float)n;
cout << "\nAverage turn around time = "
<< (float)total_tat / (float)n;
}
int main()
{
int num, temp;
      
    cout<<"Enter number of Process: ";
    cin>>num;
    int processes[num];
int burst_time[num];
    cout<<"...Enter the process ID...\n";
    for(int i=0; i<num; i++)
    {
        cout<<"...Process "<<i+1<<"...\n";
        cout<<"Enter Process Id: ";
        cin>>processes[i];
        cout<<"Enter Burst Time: ";
        cin>>burst_time[i];
    }
int n = sizeof processes / sizeof processes[0];
int quantum;
    cout<<"Enter Quantum: ";
    cin>>quantum;
findavgTime(processes, n, burst_time, quantum);
return 0;
}