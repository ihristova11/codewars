#include <iostream>

using namespace std;

const int MaxWords = 15;
const int MaxWordLength = 20;
const int MaxLengthMatrix = 20;

bool existInMatrix(char *word, char (*matrix)[MaxLengthMatrix])
{

}

void readMatrix(char(*matrix)[MaxWordLength], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> *(*(matrix + i) + j);
		}
	}
}

int main()
{
	bool flag = true;
	int index = 0;
	char sentence[MaxWords][MaxWordLength];
	char matrix[MaxLengthMatrix][MaxLengthMatrix];


	int m, n;
	cin >> m >> n;

	readMatrix(matrix, m, n);

	return 0;
}