#include <iostream>

int main()
{
	int n;

	std::cin >> n;
	int i;

	// minimal sum = sum of the prime factors 
	for (i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			std::cout << i << " " << std::endl;

			n /= i;
		}
	}

	if (n > 1)
	{
		std::cout << n << " " << std::endl;
	}

	return 0;
}