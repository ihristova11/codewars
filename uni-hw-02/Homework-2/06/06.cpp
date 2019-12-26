#include <iostream>
#include <cmath>

const int MaxLength = 10;

int min(int a, int b)
{
	return a > b ? b : a;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

// using dynamic programming
int findLargestSquare(int(*matrix)[MaxLength], int n)
{
	// construct a helper matrix
	int temp[MaxLength][MaxLength] = { 0 };
	int res = 0;

	// algorithm for finding the side of the square: 
	// 1. put 1 in the cell of the helper matrix if i == 0 or j == 0 or all adjacent elements are not 0s
	// 2. if the adjacent elements are all 0s -> find the minimum of the adjacent elements in the helper matrix and add 1
	// 3. keep track of the maximum element in the helper matrix

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0)
			{
				temp[i][j] = 1;
			}
			else
			{
				if (*(*(matrix + i) + j) == 0 &&
					*(*(matrix + i - 1) + j) == 0 &&
					*(*(matrix + i) + j - 1) == 0 &&
					*(*(matrix + i - 1) + j - 1) == 0)
				{
					temp[i][j] = min(min(temp[i - 1][j], temp[i][j - 1]), temp[i - 1][j - 1]) + 1;
				}

				else
				{
					temp[i][j] = 1;
				}
			}

			res = max(res, temp[i][j]);
		}
	}
	res *= res;
	return res;
}

void readMatrix(int(*matrix)[MaxLength], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> *(*(matrix + i) + j);
		}
	}
}

int main()
{
	int n;
	int matrix[MaxLength][MaxLength];

	std::cin >> n;
	readMatrix(matrix, n, n);

	std::cout << findLargestSquare(matrix, n) << std::endl;

	return 0;
}