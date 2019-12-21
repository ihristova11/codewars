#include <iostream>
#include <cstring>

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
	int arr[26] = { 0 };
	int duplicates = 0;

	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			arr[in[i] - 'A']++;
		}
		else
		{
			arr[in[i] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > 1)
		{
			duplicates++;
		}
	}

	return duplicates;
}

int main()
{
	std::cout << duplicateCount("aabbcde");

	return 0;
}