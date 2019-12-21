#include <iostream>

#include <iostream>
#include <stack>

std::string number_to_string(int num) {
	std::string result = "";
	std::stack<int> st;
	int digit;
	bool negative = false;

	if (num < 0)
	{
		result += '-';
		num *= -1;
	}

	if (num == 0)
	{
		result = '0';
	}
	else
	{

		while (num != 0)
		{
			st.push(num % 10);
			num = num / 10;
		}

		while (!st.empty())
		{
			digit = st.top();
			st.pop();
			result += '0' + digit;
		}
	}

	return result;
}

int main()
{
	std::cout << number_to_string(0) << std::endl;
}