#include <iostream>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
	int len = numbers.size();
	int n = 0;
	for (int i = 0; i < len; i++)
	{
		n = n ^ numbers[i];
	}

	return n;
}

int main()
{
	return 0;
}