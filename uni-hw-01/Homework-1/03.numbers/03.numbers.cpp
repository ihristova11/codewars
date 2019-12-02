#include <iostream>
using namespace std;

int main()
{
	// generate all numbers with the digits given 
	// check whether the number is in the interval
	// print in ascending number

	int a, b, n, num;
	int digits[10];
	bool flag = true;
	cin >> a >> b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> digits[i];
	}

	for (int i = a; i <= b; i++)
	{
		flag = true;
		num = i;
		while (num > 0)
		{
			int rem = num % 10;
			for (int j = 0; j < n; j++)
			{
				if (rem == digits[j] && i < 10)
				{
					flag = true;
					break;
				}
				if (rem != digits[j] && i >= 10)
				{

				}
			}

			if (!flag)
			{
				break;
			}

			num = num / 10;
		}

		if (flag)
		{
			cout << i << " ";
		}
	}


	return 0;
}