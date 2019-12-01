#include <iostream>
#include <string>

void reverse(char* arr, int length)
{
	int i;

	for (i = 0; i < length / 2; i++)
	{
		char temp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = temp;
	}
}

int getDigit(char ch)
{
	int digit;

	if (ch >= '0' && ch <= '9')
	{
		digit = (int)ch - '0';
	}
	else
	{
		digit = (int)ch - 'A' + 10;
	}

	return digit;
}

char getChar(int digit)
{
	char res;
	if (digit >= 0 && digit <= 9)
	{
		res = (char)(digit + '0');
	}
	else
	{
		res = (char)(digit - 10 + 'A');
	}
	
	return res;
}

int toDecimal(char* arr, int length, int fromBase)
{
	int num = 0,
		pow = 1,
		i;

	for (i = length - 1; i >= 0; i--)
	{
		num += getDigit(arr[i]) * pow;
		pow = pow * fromBase;
	}

	return num;
}

char* fromDecimal(char res[],  int toBase, int number)
{
	int ind = 0;  

	while (number > 0)
	{
		res[ind++] = getChar(number % toBase);
		number /= toBase;
	}
	res[ind] = '\0';

	reverse(res, ind);

	return res;
}

void print(char* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i];
	}
}

int main()
{
	int const MaxLength = 20;

	char n[MaxLength], result[MaxLength];
	int fromBase, toBase, l = 0, decimal;

	std::cin >> n;
	std::cin >> fromBase >> toBase;

	l = strlen(n);

	// convert to decimal
	decimal = toDecimal(n, l, fromBase);

	// convert from decimal to target base
	fromDecimal(result, toBase, decimal);

	// print the result
	print(result, strlen(result));

	return 0;
}