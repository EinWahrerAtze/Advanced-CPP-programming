//
//  main.cpp
//  4.8.2
//
//  Created by Den Fedorov on 06.09.2022.
//

#include <iostream>
#include "Print_container.hpp"

auto main() -> int
{
//	system("clear");
	std::vector<std::string> vec{ "one", "two", "three", "four", "five", "six" };
	std::array<int, 6> arr{ 1, 2, 3, 4, 5, 6 };
	std::list<double> lst{ 1.0, 95.3, 44,8, 12,2, 0.55, 5.5 };
	std::set<std::string> st{ "one", "two", "three", "four", "five", "six" };
	std::string str{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	std::map<char, int> mp_one{ {'c', 3}, {'b', 2}, {'a', 1} };
	std::map<std::string, float> mp_two{ {"black", 0.1}, {"white", 0.2}, {"blue", 0.3}, {"red", 0.4} };


	print_container(vec);
	std::cout << '\n';
	print_container(arr);
	std::cout << '\n';
	print_container(lst);
	std::cout << '\n';
	print_container(st);
	std::cout << '\n';
	print_container(str);
	std::cout << '\n';
	print_container(mp_one);
	std::cout << '\n';
	print_container(mp_two);
	std::cout << '\n';

	return 0;
}

