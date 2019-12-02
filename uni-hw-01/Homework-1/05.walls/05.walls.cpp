#include <iostream>
#include <cmath>

int main()
{
	const int MaxLength = 1000;
	int n, i, max, maxInd = 0, secondMax, secondMaxInd = 0, sum = 0;
	int walls[MaxLength] = { 0 };

	std::cin >> n;

	for (i = 0; i < n; i++)
	{
		std::cin >> walls[i];
	}

	max = walls[0];
	secondMax = walls[0];

	for (i = 0; i < n; i++)
	{
		if (walls[i] > max)
		{
			max = walls[i];
			maxInd = i;
		}
	}

	walls[maxInd] = INT_MIN;

	for (i = 0; i < n; i++)
	{
		if (walls[i] > secondMax)
		{
			secondMax = walls[i];
			secondMax = i;
		}
	}

	sum += abs(maxInd - secondMaxInd) * secondMax;

	if (maxInd < secondMaxInd)
	{
	}

	std::cout << sum << std::endl;

	return 0;
}