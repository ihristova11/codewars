#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 256;

bool isInArray(char ch, char* arr)
{
	int len = strlen(arr);
	bool isReplaced = false;
	bool flag = false;

	for (int i = 0; i < len; i++)
	{
		flag = (flag | (arr[i] == ch));

		if (arr[i] == ch && !isReplaced)
		{
			arr[i] = '0';
			isReplaced = true;
		}
	}

	return flag;
}

bool areAllInArray(char* a, char* c)
{
	int len = strlen(a);
	bool flag = true;

	for (int i = 0; i < len; i++)
	{
		flag = flag & isInArray(a[i], c);
	}

	return flag;
}

bool isResultOfConcatenation(char* a, char* b, char* c)
{
	return areAllInArray(a, c) && areAllInArray(b, c);
}

int main()
{
	char a[MaxLength], 
		b[MaxLength], 
		c[MaxLength];
	cin >> a;
	cin >> b;
	cin >> c;

	cout << (isResultOfConcatenation(a, b, c) ? "true" : "false") << endl;

	return 0;
}