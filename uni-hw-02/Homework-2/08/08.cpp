#include <iostream>

using namespace std;

const int MaxLength = 23;

int sumRow(int(*matrix)[MaxLength], int n, int row)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += abs(*(*(matrix + row) + i));
	}

	return sum;
}

bool isDominant(int(*matrix)[MaxLength], int n)
{
	int absolute = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		absolute = abs(*(*(matrix + i) + i));
		flag = (flag & (absolute >= (sumRow(matrix, n, i) - absolute)));
	}

	return flag;
}

int main()
{
	int matrix[MaxLength][MaxLength];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << boolalpha << isDominant(matrix, n) << endl;

	return 0;
}