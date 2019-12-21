// Sum of cubes

#include <iostream>

unsigned int sum_cubes(unsigned int n) {
	unsigned int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += (i * i * i);
	}

	return sum;
}

int main()
{
	return 0;
}