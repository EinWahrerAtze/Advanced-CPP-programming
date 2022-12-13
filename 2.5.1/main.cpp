//
//  main.cpp
//  4.5.1
//
//  Created by Den Fedorov on 03.09.2022.
//

#include <iostream>
#include <vector>
#include <array>
#include <type_traits>
#include <stdexcept>

template<typename T>
auto multiplication(T & t) -> void
{	// if argument is c-style array
	if constexpr (std::is_array_v<T>)
	{
		for (auto & n : t)
		{
			n *= n;
		}
	} // if argument is fundamental type
	else if constexpr (std::is_fundamental_v<T>)
	{
		t *= t;
	}
	else
	{
		throw std::invalid_argument("\nWrong argument!");
	}
}

// multiplication overloading for std::vector
template<typename T>
auto multiplication(std::vector<T> & vec) -> void
{
	for (auto & n : vec)
	{
		n *= n;
	}
}

auto main(int argc, const char * argv[]) -> int
{
	int n_value{ 4 };
	float f_value{ 5.5f };
	int old_array[6]{ 1, 2, 3, 4, 5, 6 };
	std::array<int, 6> new_array{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };

	std::cout << "Before multiplication:\n";
	std::cout << "int value: " << n_value << '\n';
	std::cout << "float value: " << f_value << '\n';
	std::cout << "vecor: ";

	for (const auto & n : new_array)
	{
		std::cout << n << ' ';
	}

	std::cout << '\n' << "array: ";

	for (int i = 0; i < 6; ++i)
	{
		std::cout << old_array[i] << ' ';
	}

	std::cout << '\n' << "std::array: ";

	for (const auto & n : new_array)
	{
		std::cout << n << ' ';
	}

	std::cout << '\n';

	try
	{
		multiplication(n_value);
		multiplication(f_value);
		multiplication(vec);
		multiplication(old_array);
		multiplication(new_array);
	}
	catch (const std::invalid_argument & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "\nAfter multiplication:\n";
	std::cout << "int value: " << n_value << '\n';
	std::cout << "float value: " << f_value << '\n';
	std::cout << "vecor: ";

	for (const auto & n : vec)
	{
		std::cout << n << ' ';
	}

	std::cout << '\n' << "array: ";

	for (int i = 0; i < 6; ++i)
	{
		std::cout << old_array[i] << ' ';
	}

	std::cout << '\n' << "std::array: ";

	for (const auto & n : new_array)
	{
		std::cout << n << ' ';
	}

	std::cout << '\n';

	return 0;
}