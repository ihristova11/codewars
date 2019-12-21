#include <iostream>
#include <cstring>

using namespace std;

const int MinsInHour = 60;
const int MaxLength = 20;
const int NMax = 100;
const int MinLength = 10;

// this function has an overload (because I need to swap also doubles)
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swap(double* xp, double* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(double* x, double* y, int* minutes, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
		{
			if (minutes[j] > minutes[j + 1])
			{
				// sort all 3 arrays
				swap(&minutes[j], &minutes[j + 1]);
				swap(&x[j], &x[j + 1]);
				swap(&y[j], &y[j + 1]);
			}
		}
}

int convertToMinutes(int hours, int minutes)
{
	return hours * MinsInHour + minutes;
}

void parseArguments(char* xArg, char* yArg, char* hoursArg, char* minutesArg, double* x, double* y, int* minutes, int index)
{
	int h, min;

	// parse x coordinate
	x[index] = atof(xArg + 1);

	// parse y coordinate
	y[index] = atof(yArg);

	// parse hours
	h = atoi(hoursArg);

	// parse minutes
	min = atoi(minutesArg);

	minutes[index] = convertToMinutes(h, min);
}

double findDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(2.0, (x1 - x2)) + pow(2, (y1 - y2)));
}

bool isOnPlace(double* x, double* y, int n)
{
	return (findDistanceBetweenTwoPoints(x[n - 1], y[n - 1], x[0], y[0]) == 0);
}

double calculateDistance(double* x, double* y, int n)
{
	double result = 0;

	for (int i = 0; i < n - 1; i++)
	{
		result += findDistanceBetweenTwoPoints(x[i], y[i], x[i + 1], y[i + 1]);
	}

	return result;
}

int main()
{
	// since we are not allowed to implement a structure, 
	// 3 arrays will be used
	double x[NMax] = { 0 };
	double y[NMax] = { 0 };
	int minutes[NMax] = { 0 };
	int n;

	char xArg[MinLength];
	char yArg[MinLength];
	char hoursArg[MinLength];
	char minutesArg[MinLength];

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		cin.getline(xArg, 10, ',');
		cin.getline(yArg, 10, ',');
		cin.getline(hoursArg, 10, ':');
		cin.getline(minutesArg, 10, '\n');

		parseArguments(xArg, yArg, hoursArg, minutesArg, x, y, minutes, i);

		// erase values of these arrays
		strcpy_s(xArg, "");
		strcpy_s(yArg, "");
		strcpy_s(hoursArg, "");
		strcpy_s(minutesArg, "");
	}

	cout << calculateDistance(x, y, n) << endl;
	cout << isOnPlace(x, y, n) << endl;

	return 0;
}