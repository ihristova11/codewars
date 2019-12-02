#include <iostream>

int main()
{
	const int MaxLength = 1001;
	char arr[MaxLength];
	int number = 0, max = 0;

	std::cin.getline(arr, MaxLength);

	for (int i = 0; i < MaxLength; i++)
	{
		if (arr[i] == '\0')
		{
			break;
		}
		
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			if (number != 0)
			{
				number *= 10;
			}
			number += (arr[i] - '0');
		}
		else
		{
			max = max < number ? number : max;
			number = 0;
		}
	}

	std::cout << max << std::endl;

	return 0;
}