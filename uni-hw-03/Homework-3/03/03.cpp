#include <iostream>
#include <cstring>

using namespace std;

// if first -> remove the space after
// if end -> remove space before
// if in the middle -> remove space before

char* remove(char* str, char* word)
{
	int lenText = strlen(str);
	int lenWord = strlen(word);

	char* result = new char[lenText]; // this will be the result arr
	char* ptr;
	char* search = str;
	int newTextLength = 0;
	bool end = false;
	// find the word 
	//while (!end)
	//{
	//	ptr = strstr(search, word);

	//	if (ptr)
	//	{
	//		// is first
	//		if (strcmp(ptr, str) != 0)
	//		{
	//			cout << "emi ne e";
	//		}
	//		else // if it is first and is not part of another word
	//		{
	//			// if the next one is a letter or number
	//			if (!(((ptr + lenWord)[0] >= 'a' && (ptr + lenWord)[0] <= 'z') ||
	//				((ptr + lenWord)[0] >= 'A' && (ptr + lenWord)[0] <= 'Z') ||
	//				((ptr + lenWord)[0] >= '0' && (ptr + lenWord)[0] <= '9')))
	//			{
	//				// we can remove it
	//			}

	//		}
	//		// is last
	//		// is middle
	//		cout << "yes";
	//		search = ptr + lenWord;
	//	}
	//	else
	//	{
	//		end = true;
	//	}


	for (int i = 0; i < lenText; ++i) // text
	{
		bool isMatch = false;
		for (int j = 0; j < lenWord; ++j)
		{
			if (str[i + j] == word[j])
			{
				continue;
			}
			else
			{
				isMatch = true;
				break;
			}
		}
		if (isMatch)
		{
			if (not (result[newTextLength] == ' ' and str[i] == ' '))
				result[newTextLength++] = str[i];
		}
		else
		{
			i += lenWord - 1; // skip the pattern (-1 cuz of the loop step = ++i)
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
	char str[] = "I love math catsand cats cats programming.";
	char word1[] = "cats";
	char word2[] = "dogs";
	cout << remove(str, word1) << endl;// << replace(str, word1, word2);
	return 0;
}
