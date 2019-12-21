#include <iostream>

std::string get_middle(std::string input)
{
	std::string result = "";
	int len = input.size();
	if (len % 2 == 1)
	{
		result = input[len / 2];
	}
	else
	{
		result = input.substr(len / 2 - 1, 2);
	}

	return result;
}

int main()
{
	return 0;
}
