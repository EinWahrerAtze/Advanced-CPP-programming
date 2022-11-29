//
//  main.cpp
//  4.7.1
//
//  Created by Den Fedorov on 05.09.2022.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define pair std::pair<char, int>

auto main(int argc, const char * argv[]) -> int
{
	std::string s{ "Hello, world!!" };
	std::map<char, int> mp;

	std::for_each(std::begin(s), std::end(s), [&mp](char ch) -> void
	{
		++mp[ch];
	});
	std::vector<pair> vec;

	std::for_each(std::begin(mp), std::end(mp), [&mp, &vec](const pair & p) -> void
	{
		vec.push_back(p);
	});
	std::sort(std::begin(vec), std::end(vec), [](const pair & lhs, const pair & rhs) -> bool
	{
		return lhs.second > rhs.second;
	});

	for (const auto & i : vec)
	{
		std::cout << i.first << ": " << i.second << '\n';
	}

	return 0;
}
