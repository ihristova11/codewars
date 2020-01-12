#include <iostream>
#include <cstring>

using namespace std;

// if first -> remove the space after
// if end -> remove space before
// if in the middle -> remove space before

bool isAlphaNumeric(char a)
{
	return((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'));
}

char* remove(char* str, char* word)
{
	int lenText = strlen(str);
	int lenWord = strlen(word);
	bool flag = true;
	char* result = new char[lenText]; // this will be the result arr
	int newTextLength = 0;

	for (int i = 0; i < lenText; ++i) // text
	{
		bool notMatched = false;
		for (int j = 0; j < lenWord; ++j)
		{
			if (str[i + j] != word[j])
			{
				notMatched = true;
				break;
			}
		}

		if (notMatched) // diff symbol
		{
			if (newTextLength == 0 && str[i] == ' ') // remove from start
			{
				continue;
			}
			if (!(result[newTextLength - 1] == ' ' && str[i] == ' '))
			{
				result[newTextLength++] = str[i];
				cout << result << endl;
			}
		}
		else
		{
			flag = true;
			// check if word
			if (i - 1 > 0)
			{
				// check prev
				flag = flag & (!isAlphaNumeric(str[i - 1]));
			}
			if (i + lenWord < lenText)
			{
				// check next
				flag = flag & (!isAlphaNumeric(str[i + lenWord]));
			}

			if (flag)
			{
				cout << result << endl;
				i += lenWord - 1; // skip the pattern (-1 cuz of the loop step = ++i)
			}
			else
			{
				result[newTextLength++] = str[i];
			}
		}
	}

	result[newTextLength] = '\0';
	return result;
}

char* replace(char* str, char* pattern, char* replaced)
{
	int lenTxt = strlen(str);
	int lenPattern = strlen(pattern);
	int lenReplaced = strlen(replaced);
	int maxNewChars;
	if (lenPattern > lenReplaced) maxNewChars = 0;
	else maxNewChars = (lenTxt / lenPattern) * (lenReplaced - lenPattern);
	char* result = new char[lenTxt + maxNewChars];
	int newTextLength = 0;
	for (int i = 0; i < lenTxt; ++i)
	{
		bool matched = false; // false if current char is not the beginning of a match of the pattern 
		for (int j = 0; j < lenPattern && i + j < lenTxt; ++j)
		{
			if (str[i + j] == pattern[j]) // still it is not guaranteed that the pattern is found
				continue;
			else
			{
				matched = true; // first difference found so our char is not beginning of a match
				break;
			}
		}
		if (!matched)
		{
			for (int j = 0; j < lenReplaced; ++j)
				result[newTextLength++] = replaced[j]; // add replaced word in the result
			i += lenPattern - 1; // skip the pattern (-1 cuz of the loop step = ++i)
		}
		else
			result[newTextLength++] = str[i];
	}
	result[newTextLength] = '\0';
	return result;
}

int main()
{
	char str[] = "one one one someone one one some one one one.";
	char word1[] = "one";
	char word2[] = "dogs";
	cout << "result:" << remove(str, word1) << endl;// << replace(str, word1, word2);
	//cout << replace(str, word1, word2) << endl;
	return 0;
}
