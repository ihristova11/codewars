#include <iostream>
#include <cstring>

const int MaxRC = 50; // max row-col length

void printCoordinates(int x, int y)
{
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

int findMinCol(int(*matrix)[MaxRC], int cols, int col)
{
	int min = INT_MAX;

	for (int i = 0; i < cols; i++)
	{
		min = min > * (*(matrix + i) + col) ? *(*(matrix + i) + col) : min;
	}

	return min;
}

int findMaxRow(int(*matrix)[MaxRC], int rows, int row)
{
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
	{
		max = max < *(*(matrix + row) + i) ? *(*(matrix + row) + i) : max;
	}

	return max;
}

bool isSaddlePoint(int el, int maxRow, int* minCols, int col)
{
	int minCol = minCols[col];

	if (maxRow != el)
	{
		return false;
	}

	if (minCol != el)
	{
		return false;
	}

	return true;
}

void findSaddlePoint(int(*matrix)[MaxRC], int m, int n)
{
	int maxRow;
	bool hasFound = false;
	int minCols[MaxRC];

	for (int c = 0; c < m; c++)
	{
		minCols[c] = findMinCol(matrix, m, c);
	}

	for (int i = 0; i < m; i++)
	{
		maxRow = findMaxRow(matrix, m, i);
		for (int j = 0; j < n; j++)
		{
			if (isSaddlePoint(*(*(matrix + i) + j), maxRow, minCols, j))
			{
				hasFound = true;
				printCoordinates(i, j);
			}
		}
	}

	if (!hasFound)
	{
		std::cout << "no such point found" << std::endl;
	}
}

void readMatrix(int(*matrix)[MaxRC], int m, int n)
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
	int m, n;
	int matrix[MaxRC][MaxRC];

	std::cin >> m >> n;

	readMatrix(matrix, m, n);
	findSaddlePoint(matrix, m, n);

	return 0;
}