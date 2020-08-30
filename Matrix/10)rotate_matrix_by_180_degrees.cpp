#include <iostream>
#include <iomanip>
using namespace std;

#define N 4

// In-place rotate the matrix by 180 degrees in anti-clockwise direction
void rotateMatrix(int mat[N][N])
{
	// rotate matrix by 180 degrees
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N; j++)
			swap(mat[i][j], mat[N - i - 1][N - j - 1]);

	// handle the case when matrix has odd dimensions
	if (N & 1) {
		for (int j = 0; j < N/2; j++)
			swap(mat[N/2][j], mat[N/2][N - j - 1]);
	}

	// print the matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << mat[i][j];
		cout << '\n';
	}
}

// In-place rotate the matrix by 180 degrees
int main()
{
	int mat[N][N] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	rotateMatrix(mat);

	return 0;
}