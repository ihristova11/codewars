#include <iostream>
#include <cstring>

using namespace std;

const int MaxLength = 100;
const int MaxSentenceLength = 4097;

void replaceWord(char* ptr, int wordToBeReplacedLength, char* wordToReplaceWith, char* sentence)
{
	char helper[MaxLength];
	int sentenceLen = strlen(sentence),
		len = sentenceLen - strlen(ptr) + wordToBeReplacedLength,		
		helperLen = 0;
	strncpy(helper, ptr + wordToBeReplacedLength, len);
	helper[len] = '\0';

	helperLen = strlen(helper);

	if (wordToBeReplacedLength > strlen(wordToReplaceWith))
	{
		strncpy(ptr, wordToReplaceWith, wordToBeReplacedLength);
		sentence[sentenceLen - helperLen - wordToBeReplacedLength + strlen(wordToReplaceWith)] = '\0';
	}
	else
	{
		strncpy(ptr, wordToReplaceWith, strlen(wordToReplaceWith));
		sentence[sentenceLen - helperLen + wordToBeReplacedLength] = '\0';
	}

	sentenceLen = strlen(sentence);

	strncpy(sentence + sentenceLen, helper, helperLen);
	sentence[sentenceLen + strlen(helper)] = '\0';
}

//int replaceWord(int endIndex, int wordToBeReplacedLength, char* wordToReplaceWith, char* sentence)
//{
//	int startIndex = endIndex - wordToBeReplacedLength,
//		sentenceLen = 0,
//		helperLen = 0;
//	char helper[MaxLength];
//
//	// copy the rest of the sentence in helper arr
//	strncpy(helper, sentence + endIndex, strlen(sentence) - endIndex);
//	helper[strlen(sentence) - endIndex] = '\0';
//	helperLen = strlen(helper);
//
//	if (wordToBeReplacedLength > strlen(wordToReplaceWith))
//	{
//		strncpy(sentence + startIndex, wordToReplaceWith, wordToBeReplacedLength); 
//		sentence[startIndex + wordToBeReplacedLength] = '\0';
//	}
//	else
//	{
//		strncpy(sentence + startIndex, wordToReplaceWith, strlen(wordToReplaceWith));
//		sentence[startIndex + strlen(wordToReplaceWith)] = '\0';
//	}
//	
//	sentenceLen = strlen(sentence);
//
//	strncpy(sentence + sentenceLen, helper, helperLen);
//	sentence[sentenceLen + strlen(helper)] = '\0';
//
//	return sentenceLen - 1;
//}

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
	char* ptr;
	for (int i = 0; i < n; i++)
	{
		ptr = strstr(sentence, keys[i]);
		if (ptr)
		{
			replaceWord(ptr, strlen(keys[i]), values[i], sentence);
		}
	}/*

	char wordFound[MaxLength];
	int ind = 0, indexFound = -1, wordInd = 0;
	while (sentence[ind] != '\0')
	{
		while ((sentence[ind] >= 'a' && sentence[ind] <= 'z') || (sentence[ind] >= 'A' && sentence[ind] <= 'Z') || sentence[ind] == ' ')
		{
			wordFound[wordInd] = sentence[ind];
			++ind;
			++wordInd;
		}
		wordFound[wordInd] = '\0';
		indexFound = isWordInDictionary(wordFound, keys, n);
		if (indexFound != -1)
		{
			ind = replaceWord(ind, wordInd, values[indexFound], sentence);
		}
		++ind;
		strcpy_s(wordFound, "");
		wordInd = 0;
	}*/
}

int main()
{
	// dictionary
	char keys[MaxLength][MaxLength];
	char values[MaxLength][MaxLength];
	char sentence[MaxSentenceLength];

	int n;
	cin >> n;
	cin.ignore();
	// fill in the dictionary
	for (int i = 0; i < 2 * n; i++)
	{
		if (i % 2 == 0)
		{
			cin.getline(keys[i / 2], MaxLength);
		}
		else
		{
			cin.getline(values[i / 2], MaxLength);
		}
	}
	cin.getline(sentence, MaxSentenceLength);

	modifySentence(sentence, keys, values, n);

	// print the sentence
	cout << sentence << endl;

	return 0;
}