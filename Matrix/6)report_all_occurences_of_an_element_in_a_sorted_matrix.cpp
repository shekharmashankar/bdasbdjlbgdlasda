#include <iostream>
using namespace std;

// M x N matrix
#define M 4
#define N 5

void findElement(int mat[][N], int key)
{
	// start from (0, N-1) i.e. top-rightmost cell of matrix
	int i = 0, j = N - 1;

	// run till matrix boundary is reached
	while (i <= M - 1 && j >= 0)
	{
		// if curr element is less than the key, increment row index
		if (mat[i][j] < key)
			i++;

		// if curr element is more than the key, decrement col index
		else if (mat[i][j] > key)
			j--;

		else	// curr element is equal to the key
		{
			cout << "Element " << key << " found at position ("
				 << i << ", " << j << ")" << '\n';

			i++; j--;
		}
	}
}

int main()
{
	int mat[M][N] =
	{
		{ -4, -3, -1,  3,  5 },
		{ -3, -2,  2,  4,  6 },
		{ -1,  1,  3,  5,  8 },
		{  3,  4,  7,  8,  9 }
	};

	findElement(mat, 3);

	return 0;
}