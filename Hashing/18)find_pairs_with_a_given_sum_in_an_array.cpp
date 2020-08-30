#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to find pair with given difference in the array
// This method do not handle duplicates in the array
void findPair(int arr[], int n, int diff)
{
	// array is unsorted

	// take an empty set
	unordered_set<int> set;

	// do for each element in the array
	for (int i = 0; i < n; i++)
	{
		// check if pair with given difference (arr[i], arr[i]-diff) exists
		if (set.find(arr[i] - diff) != set.end())
			cout << "(" << arr[i] << ", " << arr[i] - diff<< ")\n";

		// check if pair with given difference (arr[i]+diff, arr[i]) exists
		if (set.find(arr[i] + diff) != set.end())
			cout << "(" << arr[i] + diff << ", " << arr[i] << ")\n";

		// insert element into the set
		set.insert(arr[i]);
	}
}

int main()
{
	int arr[] = { 1, 5, 2, 2, 2, 5, 5, 4};
	int diff = 3;

	int n = sizeof(arr) / sizeof(arr[0]);

	findPair(arr, n, diff);

	return 0;
}