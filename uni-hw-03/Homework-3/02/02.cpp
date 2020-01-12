#include <iostream>
using namespace std;

// should be declared because we use them 
// in first function implementation
void turnOnAll(int n);
void turnOffAll(int n);

// turns on the first lamp only
void turnFirstOn(int p)
{
	if (p == 1)
	{
		cout << "+1" << endl;
	}
	else 
	{
		turnFirstOn(p - 1);
		cout << "+" << p << endl;
		turnOffAll(p - 1);
	}
}

// turns on all lamps in the line
void turnOnAll(int n)
{
	if (n == 1)
	{
		cout << "+1" << endl;
	}
	else if (n == 2)
	{
		cout << "+1" << endl << "+2" << endl;
	}
	else
	{
		turnFirstOn(n - 1);
		cout << "+" << n << endl;
		turnOnAll(n - 2);
	}
}

// turns off all the lamps in the line
void turnOffAll(int n)
{
	if (n == 1)
	{
		cout << "-1" << endl;
	}
	else
	{
		turnFirstOn(n - 1);
		cout << "-" << n << endl;
		turnOffAll(n - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	turnOnAll(n);
	return 0;
}
