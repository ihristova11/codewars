#include <iostream>
#include <cstring>

using namespace std;

const int MaxNumber = 4;
const int MaxRC = 50; // max row-col length

void printCoordinates(int x, int y)
{
	cout << "(" << x << ", " << y << ")" << endl;
}

int findMinCol(int(*matrix)[MaxRC], int cols, int col)
{
	int min = INT_MAX;

	for (int i = 0; i < cols; i++)
	{
		min = min >= * (*(matrix + i) + col) ? *(*(matrix + i) + col) : min;
	}

	return min;
}

int findMaxRow(int(*matrix)[MaxRC], int rows, int row)
{
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
	{
		max = max <= *(*(matrix + row) + i) ? *(*(matrix + row) + i) : max;
	}

	return max;
}

bool checkElement(int el, int maxRow, int* minCols, int col)
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
			if (checkElement(*(*(matrix + i) + j), maxRow, minCols, j))
			{
				hasFound = true;
				printCoordinates(i, j);
			}
		}
	}

	if (!hasFound)
	{
		cout << "no such point found" << endl;
	}
}

int main()
{
	char a[MaxNumber];
	char b[MaxNumber];
	int m, n;
	int matrix[MaxRC][MaxRC];

	cin.getline(a, MaxNumber, ',');
	cin.getline(b, MaxNumber);

	m = atoi(a);
	n = atoi(b);

	// read the matrix
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> matrix[i][k];
		}
	}

	findSaddlePoint(matrix, m, n);

	return 0;
}