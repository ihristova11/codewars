#include <iostream>
#include <cstring>

const int MaxLength = 20;

int min(int a, int b)
{
	return a < b ? a : b;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void modifyMatrix(int(*matrix)[MaxLength], int minimal)
{	
	for (int i = 0; i < minimal; i++)
	{
		for (int j = 0; j != i && j < i; j++)
		{
			if (matrix[i][j] > matrix[j][i])
			{
				swap(&matrix[i][j], &matrix[j][i]);
			}
		}
	}
}

void printMatrix(int(*matrix)[MaxLength], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << *(*(matrix + i) + j) << " ";
		}
		std::cout << std::endl;
	}
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
	int matrix[MaxLength][MaxLength];
	int m, n, minimal;

	std::cin >> m >> n;
	minimal = min(m, n);

	readMatrix(matrix, m, n);
	modifyMatrix(matrix, minimal);
	printMatrix(matrix, m, n);

	return 0;
}