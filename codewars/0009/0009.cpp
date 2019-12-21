// You're a square!

#include <iostream>
#include <cmath>

bool is_square(int n)
{
	double sr = sqrt(n);

	return ((sr - floor(sr)) == 0);
}

int main()
{
	return 0;
}