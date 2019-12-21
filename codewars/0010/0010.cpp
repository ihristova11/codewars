// Calculate BMI

#include <iostream>
std::string bmi(double w, double h)
{
	double bmi = w / h / h;
	if (bmi <= 18.5) return "Underweight";
	if (bmi <= 25.0) return "Normal";
	if (bmi <= 30.0) return "Overweight";
	return "Obese";
}

int main()
{
	std::cout << bmi(86.7, 1.7);
	return 0;
}
