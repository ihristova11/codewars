#include <iostream>

int findPairsWithSum(int arr[], int n, int sum)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	const int MaxLength = 200;
	int n, sum, pairs = 0;
	int seq[MaxLength];

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
	}

	std::cin >> sum;

	pairs = findPairsWithSum(seq, n, sum);
	std::cout << pairs << std::endl;

	return 0;
}