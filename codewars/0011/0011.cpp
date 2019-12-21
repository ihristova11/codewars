// Count the Monkeys!

#include <iostream>
#include <vector>

std::vector<int> MonkeyCount(int n) {
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(i + 1);
	}

	return v;
}
int main()
{
	return 0;
}