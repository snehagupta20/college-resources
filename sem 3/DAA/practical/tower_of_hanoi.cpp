// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 0) 
	{
		return;
	}
	tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod
		<< " to rod " << to_rod << endl;
	tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
	int N = 3;

	// A, B and C are names of rods
	tower_of_hanoi(N, 'A', 'C', 'B');
	return 0;
}

// This is code is contributed by rathbhupendra
