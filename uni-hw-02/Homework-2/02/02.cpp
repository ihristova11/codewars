#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 100;
const int MaxSentenceLength = 4097;

void replaceWord(int endIndex, int wordToBeReplacedLength, char* wordToReplaceWith, char* sentence)
{
	int startIndex = endIndex - wordToBeReplacedLength;
	//int toEnd[MaxLength] = 

	strncpy(sentence + startIndex, wordToReplaceWith, wordToBeReplacedLength);
}

int isWordInDictionary(char* word, char(*keys)[MaxLength], int n)
{

	for (int i = 0; i < n; i++)
	{
		if (strcmp(keys[i], word) == 0)
		{
			return i;
		}
	}

	return -1;
}


void modifySentence(char* sentence, char(*keys)[MaxLength], char(*values)[MaxLength], int n)
{
	char wordFound[MaxLength];
	int ind = 0, indexFound = -1, wordInd = 0;
	while (sentence[ind] != '\0')
	{
		while ((sentence[ind] >= 'a' && sentence[ind] <= 'z') || (sentence[ind] >= 'A' && sentence[ind] <= 'Z'))
		{
			wordFound[wordInd] = sentence[ind];
			++ind;
			++wordInd;
		}
		wordFound[wordInd] = '\0';
		indexFound = isWordInDictionary(wordFound, keys, n);
		if (indexFound != -1)
		{
			replaceWord(ind, wordInd, values[indexFound], sentence);
		}
		++ind;
		strcpy_s(wordFound, "");
		wordInd = 0;
	}
}

int main()
{
	// dictionary
	char keys[MaxLength][MaxLength];
	char values[MaxLength][MaxLength];

	char sentence[MaxSentenceLength];

	int n;
	cin >> n;

	// fill in the dictionary
	for (int i = 0; i < 2 * n; i++)
	{
		if (i % 2 == 0)
		{
			cin >> keys[i / 2];
		}
		else
		{
			cin >> values[i / 2];
		}
	}
	cin.ignore();
	cin.getline(sentence, MaxSentenceLength);

	modifySentence(sentence, keys, values, n);

	// print the sentence
	cout << sentence << endl;

	return 0;
}