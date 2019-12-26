#include <iostream>

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
	int n;
	std::cin >> n;

	readMatrix(matrix, n, n);

	std::cout << std::boolalpha << isDominant(matrix, n) << std::endl;

	return 0;
}