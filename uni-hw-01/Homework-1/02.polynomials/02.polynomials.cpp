#include <iostream> 

int main()
{
	const int MaxLength = 100;

	int a[MaxLength] = { 0 }, b[MaxLength] = { 0 }, prod[MaxLength * 2] = { 0 };
	int n, m;

	std::cin >> n;

	// read the first polynomial
	for (int i = 0; i < n + 1; i++)
	{
		std::cin >> a[i];
	}

	std::cin >> m;

	// read the second polynomial
	for (int i = 0; i < m + 1; i++)
	{
		std::cin >> b[i];
	}

	// multiply the polynomials
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			prod[i + j] += a[i] * b[j];
		}
	}

	for (int i = 0; i < n + m + 1; i++)
	{
		std::cout << prod[i] << " ";
	}

	return 0;
}