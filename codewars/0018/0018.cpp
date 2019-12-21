#include <iostream>

#include <string>
#include <unordered_map>

std::unordered_map<char, char> pairs = { {'A', 'T'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'} };

std::string DNAStrand(const std::string& dna)
{
	std::string complement;
	for (const char& c : dna)
	{
		complement += pairs[c];
	}
	return complement;
}

int main()
{
	return 0;
}