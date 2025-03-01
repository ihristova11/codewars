#include <iostream>

const int X = 0;
const int Y = 7;
const int Z = 1;

long long T(int n) // T(10) = 282 475 249
{
	if (n == 0)
	{
		return Z;
	}

	return  X * T(n / 2) + Y * T(n - 1);
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << T(n) << std::endl;

	return 0;
}
