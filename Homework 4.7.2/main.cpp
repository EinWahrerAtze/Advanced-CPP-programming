#include <stdexcept>
#include <iostream>
#include <iterator>
#include <string>
#include <set>

void clear()
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}

auto main() -> int
{
//	clear();
	std::cout << "Enter some words (CTRL + Z (or CTRL + D) -> Enter to quit):\n";

	std::set<std::string> s;
	std::istream_iterator<std::string> begin{ std::cin };
	std::istream_iterator<std::string> end;

	try
	{
		std::copy(begin, end, std::inserter(s, s.end()));
	}
	catch (const std::bad_alloc & ex)
	{
		std::cout << ex.what();
	}

	clear();
	std::cout << "You entered:\n";

	for (const auto & word : s)
	{
		std::cout << word << ' ';
	}

	std::cout << "\n\nBye!\n";
	return 0;
}
