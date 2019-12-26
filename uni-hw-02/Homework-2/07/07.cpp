#include <iostream>
#include <cstring>

const int MaxLength = 1001;

void print(char* word, int n, int l)
{
	for (int start = 0; start <= n - l; start++)
	{
		for (int len = start; len < start + l; len++)
		{
			std::cout << word[len];
		}
		std::cout << std::endl;
	}
}

void findAll(char* word, int n, int divisor)
{
	for (int l = 1; l <= n; l++)
	{
		if (l % divisor == 0)
		{
			print(word, n, l);
		}
	}
}

int main()
{
	int l;
	char word[MaxLength];
	std::cin.getline(word, MaxLength - 1);
	std::cin >> l;

	findAll(word, strlen(word), l);

	return 0;
}