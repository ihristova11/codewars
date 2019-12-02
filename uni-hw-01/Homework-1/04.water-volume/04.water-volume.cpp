#include <iostream>

int main()
{
	const int MaxLength = 1000;
	int n, i, j, min, maxVol = 0, tempVol = 0, convertion = 1000;
	int walls[MaxLength] = { 0 };

	std::cin >> n;

	for (i = 0; i < n; i++)
	{
		std::cin >> walls[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			min = walls[i] < walls[j] ? walls[i] : walls[j];
			tempVol = min * (j - i);
			maxVol = maxVol < tempVol ? tempVol : maxVol;
		}
	}

	std::cout << maxVol * convertion << std::endl;

	return 0;
}