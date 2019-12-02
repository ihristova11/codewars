#include <iostream>

int main()
{
	int n, temp = 0, min = INT_MAX;
	int divisors[3] = { 0 };
	std::cin >> n;

	for (int j = 1; j < n; j++)
	{
		if (n % j == 0)
		{
			for (int k = j; k < n / j; k++)
			{
				temp = 0;
				if ((n / j) % k == 0)
				{
					temp += (j + k + n / k);

					if (min > temp)
					{
						divisors[0] = j;
						divisors[1] = k;
						divisors[2] = n / k;

						min = temp;
					}

				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << divisors[i] << " ";
	}

	return 0;
}