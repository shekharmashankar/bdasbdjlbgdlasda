#include <iostream>
#include <unordered_map>
using namespace std;

// Function to group elements of the given array based on first occurrence
// of each element
void rearrange(int A[], int n)
{
	// create an empty map to store frequency of each element
	// present in the input array
	unordered_map<int, int> freq;

	// traverse the input array and update frequency of each element
	for (int i = 0; i < n; i++) {
		freq[A[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		// if A[i] exists in the map (first occurrence of A[i])
		if (freq.find(A[i]) != freq.end())
		{
			// print A[i] n times where n = freq[A[i]]
			int n = freq[A[i]];
			while (n--) {
				cout << A[i] << " ";
			}

			// delete the element from the map so it would not
			// get processed again
			freq.erase(A[i]);
		}
	}
}

int main()
{
	int A[] = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };
	int n = sizeof(A)/sizeof(A[0]);

	rearrange(A, n);

	return 0;
}