#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 1001;

void print(char* word, int n, int l)
{
	for (int start = 0; start <= n - l; start++)
	{
		for (int len = start; len < start + l; len++)
		{
			cout << word[len];
		}
		cout << endl;
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
	cin.getline(word, MaxLength - 1);
	cin >> l;

	findAll(word, strlen(word), l);

	return 0;
}