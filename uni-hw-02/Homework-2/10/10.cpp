#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 20;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void modifyMatrix(int(*matrix)[MaxLength], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j != i && j < i; j++)
		{
			if (matrix[i][j] < matrix[j][i])
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
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
}

void readMatrix(int(*matrix)[MaxLength], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> *(*(matrix + i) + j);
		}
	}
}

int main()
{
	int matrix[MaxLength][MaxLength];
	int m, n;

	cin >> m >> n;

	readMatrix(matrix, m, n);
	modifyMatrix(matrix, m, n);
	printMatrix(matrix, m, n);

	return 0;
}