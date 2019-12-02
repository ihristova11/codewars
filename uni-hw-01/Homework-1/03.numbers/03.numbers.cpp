#include <iostream>

bool isInDigits(int d, int* digits, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (digits[i] == d)
		{
			return true;
		}
	}
	return false;
}

int isValid(int n, int* digits, int l)
{
	int rem = 0;
	int num = n;
	while (n > 0)
	{
		rem = n % 10;
		if (isInDigits(rem, digits, l))
		{
			n /= 10;
		}
		else
		{
			break;
		}
	}

	if (n == 0)
	{
		return num;
	}

	return -1;
}

int main()
{
	const int MaxLength = 1000;

	int a, b, n, res;
	int digits[10];
	
	std::cin >> a >> b;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> digits[i];
	}

	for (int i = a; i <= b; i++)
	{
		res = isValid(i, digits, n);
		if (res != -1)
		{
			std::cout << res << " ";
		}
	}

	return 0;
}