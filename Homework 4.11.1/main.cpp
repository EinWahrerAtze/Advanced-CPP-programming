//
//  main.cpp
//  4.11.1
//
//  Created by Den Fedorov on 10.09.2022.
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <list>

template <typename T>
auto move_containers(T & t1, T & t2)
{
	try
	{
		t2 = std::move(t1);
	}
	catch (const std::bad_alloc & ex)
	{
		std::cout << ex.what() << '\n';
	}
}

template<typename T>
auto print(T const & container) -> void
{
	if (container.empty())
	{
		std::cout << "empty\n";
	}
	else
	{
		for (const auto & i : container)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}

auto main(int argc, const char * argv[]) -> int
{
	system("clear");

	std::vector<std::string> v1{ "test_string_1", "test_string_2" };
	std::vector<std::string> v2;
	std::list<int> l1{ 1, 2, 3, 4, 5 };
	std::list<int> l2;
	std::string s1{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	std::string s2;


	std::cout << "vector one: ";
	print(v1);
	std::cout << "vector two: ";
	print(v2);
	std::cout << "list one: ";
	print(l1);
	std::cout << "list two: ";
	print(l2);
	std::cout << "string one: ";
	print(s1);
	std::cout << "string two: ";
	print(s2);

	move_containers(v1, v2);
	move_containers(l1, l2);
	move_containers(s1, s2);

	std::cout << "\nvector one: ";
	print(v1);
	std::cout << "vector two: ";
	print(v2);
	std::cout << "list one: ";
	print(l1);
	std::cout << "list two: ";
	print(l2);
	std::cout << "string one: ";
	print(s1);
	std::cout << "string two: ";
	print(s2);
	std::cout << "\nBye!\n";

	return 0;
}
