#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 100;
const int MaxSentenceLength = 4097;

void replaceWord(int endIndex, int wordToBeReplacedLength, char* wordToReplaceWith, char* sentence)
{
	int wordLen = strlen(wordToReplaceWith);
	int startIndex = endIndex - wordLen;

	for (int i = 0; i < wordLen; i++)
	{
		sentence[startIndex + i] = wordToReplaceWith[i];
	}
}

int isWordInDictionary(char* word, char(*keys)[MaxLength])
{
	int len = strlen(word); //should be keys length

	for (int i = 0; i < len; i++)
	{
		if (strcmp(keys[i], word) == 0)
		{
			return i;
		}
	}

	return -1;
}


void modifySentence(char* sentence, char(*keys)[MaxLength], char(*values)[MaxLength])
{
	char wordFound[MaxLength];
	int ind = 0, indexFound = -1, wordInd = 0;
	while (sentence[ind] != '\0')
	{
		while (sentence[ind] != ' ')
		{
			wordFound[wordInd] = sentence[ind];
			++ind;
			++wordInd;
		}
		wordFound[wordInd] = '\0';
		indexFound = isWordInDictionary(wordFound, keys);
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
	char test[10] = "pruc";


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

	modifySentence(sentence, keys, values);

	// print the sentence
	cout << sentence << endl;

	return 0;
}