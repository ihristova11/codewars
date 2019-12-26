#include <iostream>
#include <cstring>

// ignore VS c/c++ preprocessor strncpy() warning 
// (https://docs.microsoft.com/en-us/cpp/preprocessor/warning?redirectedfrom=MSDN&view=vs-2019)
#pragma warning(disable:4996) 

const int MaxLength = 100;
const int MaxSentenceLength = 4097;

void replaceWord(char* ptr, int replaceableLen, char* replacement, char* sentence)
{
	char helper[MaxLength];
	int sentenceLen = strlen(sentence),
		len = strlen(ptr) - replaceableLen,
		helperLen = 0,
		replacementLen = strlen(replacement);
	strncpy(helper, ptr + replaceableLen, len);
	helper[len] = '\0';

	helperLen = strlen(helper);

	strncpy(ptr, replacement, replacementLen);
	sentence[sentenceLen - helperLen - replaceableLen + replacementLen] = '\0';

	sentenceLen = strlen(sentence);

	strncpy(sentence + sentenceLen, helper, helperLen);
	sentence[sentenceLen + helperLen] = '\0';
}

void modifySentence(char* sentence, char(*keys)[MaxLength], char(*values)[MaxLength], int n)
{
	char* ptr;
	for (int i = 0; i < n; i++)
	{
		ptr = strstr(sentence, keys[i]);
		while (ptr)
		{
			replaceWord(ptr, strlen(keys[i]), values[i], sentence);
			ptr = strstr(sentence, keys[i]);
		}
	}
}

int main()
{
	// dictionary
	char keys[MaxLength][MaxLength];
	char values[MaxLength][MaxLength];
	char sentence[MaxSentenceLength];

	int n;
	std::cin >> n;
	std::cin.ignore();
	// fill in the dictionary
	for (int i = 0; i < 2 * n; i++)
	{
		if (i % 2 == 0)
		{
			std::cin.getline(keys[i / 2], MaxLength);
		}
		else
		{
			std::cin.getline(values[i / 2], MaxLength);
		}
	}
	std::cin.getline(sentence, MaxSentenceLength);

	modifySentence(sentence, keys, values, n);

	// print the sentence
	std::cout << sentence << std::endl;

	return 0;
}