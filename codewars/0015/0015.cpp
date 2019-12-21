// Are they the same

#include <iostream>
#include <algorithm>
#include <vector>

class Same {
public:
	static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b) {
	for (auto& v : a) {
		v = v * v;
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	return a == b;
}

int main()
{
	return 0;
}