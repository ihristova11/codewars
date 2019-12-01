#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.14;
const double XR = 5;
const double YR = 2;

double findApproximateDistance(double distance)
{
	return ((PI + 2) * distance) / 4; // formula given in the assignment
}

double calculateLineEquation(
	double xDiff, double yDiff,
	double xOut, double yOut,
	double xIn, double yIn,
	double xL, double yL)
{
	double distance = 0, y = 0, x = 0;

	if (xDiff != 0)
	{
		y = (yDiff * xL - yDiff * xOut + yOut * xDiff) / xDiff;
	}

	if (yDiff != 0)
	{
		x = (xDiff * yL + yDiff * xOut - xDiff * yOut) / yDiff;
	}

	if (yDiff == 0)
	{
		distance = fabs(xL - xIn);
	}
	else if (xDiff == 0)
	{
		distance = fabs(yL - yIn);
	}


	if (xDiff != 0 && yDiff != 0)
	{
		if (x >= -1 * XR && x <= XR)
		{
			distance = sqrt(pow((xIn - x), 2.0) + pow((yIn - yL), 2.0));
		}
		else
		{
			distance = sqrt(pow((xIn - xL), 2.0) + pow((yIn - y), 2.0));
		}
	}

	return distance;
}

double findDistanceBetweenPoints(double x1, double y1, double x2, double y2)
{
	return findApproximateDistance(sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0)));
}

bool isInRectangle(double x, double y)
{
	return (x >= XR * (-1) && x <= XR) && (y >= YR * (-1) && y <= YR);
}

double findIntersectionDistance(double xIn, double yIn, double xOut, double yOut)
{
	double distance = 0;
	double xDiff = xIn - xOut;
	double yDiff = yIn - yOut;

	if (xOut >= 0) // I or IV quadrant
	{
		if (yOut >= 0) // I quadrant | intercepts with either y = 2 or x = 5
		{
			distance = calculateLineEquation(xDiff, yDiff, xOut, yOut, xIn, yIn, XR, YR);
		}
		else // IV
		{
			distance = calculateLineEquation(xDiff, yDiff, xOut, yOut, xIn, yIn, XR, -1 * YR);
		}
	}
	else // II or III quadrant
	{
		if (yOut >= 0) // II
		{
			distance = calculateLineEquation(xDiff, yDiff, xOut, yOut, xIn, yIn, -1 * XR, YR);
		}
		else // III
		{
			distance = calculateLineEquation(xDiff, yDiff, xOut, yOut, xIn, yIn, -1 * XR, -1 * YR);
		}
	}

	return findApproximateDistance(distance);
}

int main()
{
	int n;
	double x1, y1, x2, y2, sum = 0, distance = 0;
	bool isFirstInR = true, isSecondInR = true;

	std::cin >> n;

	std::cin >> x1 >> y1; // read the first pair of coordinates
	isFirstInR = isInRectangle(x1, y1);

	for (int i = 0; i < n - 1; i++)
	{
		distance = 0;
		std::cin >> x2 >> y2;
		isSecondInR = isInRectangle(x2, y2);

		if (isFirstInR && isSecondInR)
		{
			distance = findDistanceBetweenPoints(x1, y1, x2, y2);
		}
		else if (isFirstInR && !isSecondInR)
		{
			distance = findIntersectionDistance(x1, y1, x2, y2);
		}
		else if (!isFirstInR && isSecondInR)
		{
			distance = findIntersectionDistance(x2, y2, x1, y1);
		}

		sum += distance;

		x1 = x2;
		y1 = y2;
		isFirstInR = isSecondInR;
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(3) << sum << std::endl;

	return 0;
}