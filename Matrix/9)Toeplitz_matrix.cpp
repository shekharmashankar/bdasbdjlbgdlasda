#include <iostream>
using namespace std;

// M x N matrix
#define M 4
#define N 5

// Function to determine if given matrix is Toeplitz matrix or not
bool checkToepliz(int matrix[M][N])
{
	for (int i = 0; i < M - 1; i++)
		for (int j = 0; j < N - 1; j++)
			// return false if any diagonal elements have different values
			if (matrix[i][j] != matrix[i + 1][j + 1])
				return false;

	return true;
}

int main()
{
	int matrix[M][N] =
	{
		{ 3, 7, 0, 9, 8 },
		{ 5, 3, 7, 0, 9 },
		{ 6, 5, 3, 7, 0 },
		{ 4, 6, 5, 3, 7 }
	};

	if (checkToepliz(matrix))
		cout << "Toepliz matrix.";
	else
		cout << "Not a Toepliz matrix.";

	return 0;
}