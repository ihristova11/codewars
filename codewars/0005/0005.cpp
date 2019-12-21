#include <iostream>
#include <vector>

std::vector<int> maps(const std::vector<int>& values)
{
	std::vector<int> result;
	for (int i = 0; i < values.size(); i++)
	{
		result.push_back(2 * values[i]);
	}

	return result;
}

int main()
{
	std::vector<int> v = { 1,2,3 };
	return 0;
}