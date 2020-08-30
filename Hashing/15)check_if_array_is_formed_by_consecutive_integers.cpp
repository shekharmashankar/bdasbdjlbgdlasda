#include <iostream>
#include <unordered_set>
using namespace std;

// Function to check if array is formed by consecutive integers
bool checkConsecutive(int arr[], int n)
{
	int min = arr[0], max = arr[0];

	// compute minimum and maximum element in an array
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];

		if (arr[i] > max)
			max = arr[i];
	}

	// in order for an array to contain consecutive integers, the difference
	// between maximum and element element in it should be exactly n-1
	if (max - min != n - 1)
		return false;

	// create an empty set (we can also use a visited array)
	unordered_set<int> visited;

	// traverse the array and checks if each element appears only once
	for (int i = 0; i < n; i++)
	{
		// if element is seen before, return false
		if (visited.find(arr[i]) != visited.end())
			return false;

		// mark element as seen
		visited.insert(arr[i]);
	}

	// we reach here when all elements in array are distinct
	return true;
}

// Check if an array is formed by consecutive integers
int main()
{
	int arr[] = { -1, 5, 4, 2, 0, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	checkConsecutive(arr, n)? cout << "Array contains consecutive integers":
						cout << "Array do not contain consecutive integers";

	return 0;
}