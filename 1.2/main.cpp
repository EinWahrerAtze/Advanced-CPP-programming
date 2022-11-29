//
//  main.cpp
//  4.1.2
//
//  Created by Den Fedorov on 15.08.2022.
//

#include <iostream>
#include <variant>
#include <vector>

void clear()
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}

auto get_variant()->std::variant<int, std::string, std::vector<int>>
{
	std::variant<int, std::string, std::vector<int>> result;
	std::srand(std::time(nullptr));
	int n{std::rand() % 3};

	switch (n)
	{
		case 0:
		{
			result = 5;
			break;
		}
		case 1:
		{
			result = "string";
			break;
		}
		case 2:
		{
			result = std::vector<int>{1, 2, 3, 4, 5};
		}
		default:
		{
			break;
		}
	}

	return result;
}

auto main(int argc, const char * argv[])->int
{
	char ch = '0';

	while (ch != 'x' && ch != 'X')
	{
		if (std::holds_alternative<int>(get_variant()))
		{
			std::cout << std::get<int>(get_variant()) * 2 << std::endl;
		}
		else if (std::holds_alternative<std::string>(get_variant()))
		{
			std::cout << std::get<std::string>(get_variant()) << std::endl;;
		}
		else
		{
			std::vector<int> v = std::get<std::vector<int>>(get_variant());

			for (int i : v)
			{
				std::cout << i << (i == *v.rbegin() ? '\n' : ' ');
			}
		}

		std::cout << "\n'X' to exit, other key to restart: ";
		std::cin >> ch;
		clear();
	}
	
	return 0;
}