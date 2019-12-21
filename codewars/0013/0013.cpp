// Remove String Spaces

#include <iostream>
#include <string>

std::string no_space(std::string str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	return str;
}

int main()
{
	return 0;
}