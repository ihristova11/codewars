#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	int* start = new int[n];
	int* end = new int[n];
	int* lectures = new int[n]; // [i] - i-th lecture
	int* checkpoints = new int[n]; // [i] - max lectures that can be visited till end[i]

	for (unsigned i = 0; i < n; ++i)
	{
		lectures[i] = i;
		std::cin >> start[i] >> end[i];
	}

	std::sort(lectures, lectures + n, [&](int a, int b) -> bool {
		if (end[a] == end[b])
			return start[a] < start[b];
		else
			return end[a] < end[b];
		});

	int answer = 0;

	for (unsigned i = 0; i < n; ++i) // end [lectures [i]]
	{
		checkpoints[i] = 1; // at least lectures[i] can be visited
		for (unsigned j = 0; j < i; ++j) // try to visit lectures[j] and lectures[i]
		{
			if (start[lectures[i]] > end[lectures[j]]) // if we can visit them
			{
				// most optimal
				checkpoints[i] = ((checkpoints[i] < (checkpoints[j] + 1)) ? (checkpoints[j] + 1) : checkpoints[i]); 
			}
		}

		answer = ((answer < checkpoints[i]) ? checkpoints[i] : answer);
	}

	std::cout << answer << std::endl;

	return 0;
}