#include <iostream>

// should be declared because we use them 
// in first function implementation
void turnOnAll(int n);
void turnOffAll(int n);

// turns on the first lamp only
void turnFirstOn(int current)
{
	if (current == 1)
	{
		std::cout << "+1" << std::endl;
	}
	else
	{
		// recurrence call to turn on the next lamp
		turnFirstOn(current - 1);

		std::cout << "+" << current << std::endl;
		turnOffAll(current - 1);
	}
}

// turns on all lamps in the line
void turnOnAll(int n)
{
	if (n == 1)
	{
		std::cout << "+" << n << std::endl;
	}
	else if (n == 2)
	{
		std::cout << "+1" << std::endl << "+2" << std::endl;
	}
	else
	{
		turnFirstOn(n - 1);
		std::cout << "+" << n << std::endl;

		// turn on all the other lamps in the line reccurently
		turnOnAll(n - 2);
	}
}

// turns off all the lamps in the line
void turnOffAll(int n)
{
	if (n == 1)
	{
		std::cout << "-" << n << std::endl;
	}
	else
	{
		turnFirstOn(n - 1);
		std::cout << "-" << n << std::endl;

		// turn off all the other lamps in the line recurrently
		turnOffAll(n - 1);
	}
}

int main()
{
	int n;
	std::cin >> n;

	turnOnAll(n);

	return 0;
}
