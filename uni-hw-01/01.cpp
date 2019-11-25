#include <iostream>

int findSum(int n)
{
	int i, sum = 0;

	// minimal sum = sum of the prime factors 
	for  (i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			sum += i;
			n /= i;
		}
	}

	sum += n;

	return sum;
}

int main()
{
	int n;

	std::cin >> n;

	std::cout << findSum(n) << std::endl;

	return 0;
}