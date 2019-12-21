#include <iostream>


std::string how_much_i_love_you(int nb_petals)
{
	std::string arr[6] = { "I love you", "a little", "a lot", "passionately", "madly", "not at all" };
	int index = (nb_petals % 6) - 1;

	if ((nb_petals % 6) == 0)
	{
		index = 6 - 1;
	}

	return arr[index];
}

int main()
{
	return 0;
}