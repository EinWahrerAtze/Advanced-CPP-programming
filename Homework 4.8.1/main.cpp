//
//  main.cpp
//  4.8.1
//
//  Created by Den Fedorov on 06.09.2022.
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <set>

auto main() -> int
{
//	system("clear");
	std::set<int> s;
	std::vector<int> v{ 1, 1, 2, 5, 6, 1, 2, 4 };

	try
	{
		std::move(v.begin(), v.end(), std::inserter(s, s.end()));
	}
	catch (const std::bad_alloc & ex)
	{
		std::cout << ex.what();
	}

	for (int n : s)
	{
		std::cout << n << ' ';
	}

	std::cout << '\n';
	return 0;
}