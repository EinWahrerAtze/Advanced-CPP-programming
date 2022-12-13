//
//  main.cpp
//  4.3.1
//
//  Created by Den Fedorov on 30.08.2022.
//

#include <iostream>
#include <string>
#include "Smart_array.h"

auto clear() -> void
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}

template<typename T>
auto check(T & value) -> void
{
	while (!(std::cin >> value))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Wrong input! Repeat: ";
	}
}

auto menu() -> void
{
	std::cout << '\n';
	std::cout << "'A' add a new element\n";
	std::cout << "'S' add a new element at index\n";
	std::cout << "'E' get an element at index\n";
	std::cout << "'R' remove element\n";
	std::cout << "'F' fit capacity of array one to actual size\n";
	std::cout << "'C' copy array one to array two\n";
	std::cout << "'D' clear array two\n";
	std::cout << "'X' exit\n\n";
	std::cout << "Input: ";
}

auto main(int argc, const char * argv[]) -> int
{
	clear();
	std::string message{ "Hello! Here are two arrays created (S - size, C - capacity):\n" };
	//	Smart_array<int> arr_one;
	//	Smart_array<int> arr_one(10);
	//	Smart_array<int> arr_one(10, 4);
	Smart_array<int> arr_one{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Smart_array<int> arr_two(arr_one);
	//	Smart_array<int> arr_two = arr_one;

	while (true)
	{
		std::cout << message;
		std::cout << "Array one (S = " << arr_one.get_size();
		std::cout << ", C = " << arr_one.get_capacity() << "):\n";
		arr_one.print();
		std::cout << "\nArray two (S = " << arr_two.get_size();
		std::cout << ", C = " << arr_two.get_capacity() << "):\n";
		arr_two.print();

		menu();

		char ch = '0';
		std::cin >> ch;
		std::cin.ignore(10000, '\n');

		switch (ch)
		{
			case 'a':
			case 'A':
			{
				clear();
				int n;
				std::cout << "Enter a number: ";
				check(n);

				try
				{
					arr_one.add(n);
					message = std::to_string(n) += " added to the end of array one\n";
				}
				catch (const std::exception & ex)
				{
					message = ex.what();
				}

				clear();
				continue;
			}
			case 's':
			case 'S':
			{
				clear();
				int index{ 0 };
				int element{ 0 };
				std::cout << "Enter index to add a new element: ";
				check(index);
				std::cout << "Value to add: ";
				check(element);
				clear();

				try
				{
					arr_one.insert(index, element);
					message = std::to_string(element);
					message += " added to array one at index ";
					message += std::to_string(index) += '\n';
				}
				catch (const std::runtime_error & ex)
				{
					message = ex.what();
				}

				continue;
			}
			case 'e':
			case 'E':
			{
				clear();
				int index{ 0 };
				std::cout << "Enter index of an element: ";
				check(index);
				clear();

				try
				{
					message = "Element at index " + std::to_string(index) + " is ";
					message += std::to_string(arr_one[index]) + '\n';
				}
				catch (const std::runtime_error & ex)
				{
					message = ex.what();
				}

				continue;
			}
			case 'r':
			case 'R':
			{
				clear();
				int index{ 0 };
				std::cout << "Enter index of an element: ";
				check(index);
				clear();

				try
				{
					arr_one.remove(index);
					message = "Element at index ";
					message += std::to_string(index) += " removed\n";
				}
				catch (const std::runtime_error & ex)
				{
					message = ex.what();
				}

				continue;
			}
			case 'f':
			case 'F':
			{
				clear();
				arr_one.fit();
				message = "Capacity of array one has been set to its size\n";
				continue;
			}
			case 'c':
			case 'C':
			{
				clear();
				arr_two = arr_one;
				message = "Array one has been copied to array two\n";
				continue;
			}
			case 'd':
			case 'D':
			{
				clear();
				arr_two.clear();
				message = "Array two is now empty\n";
				continue;
			}
			case 'x':
			case 'X':
			{
				clear();
				std::cout << "Bye!\n";
				exit(EXIT_SUCCESS);
			}
			default:
			{
				clear();
				message = "Wrong input! Repeat: ";
				continue;
			}
		}
	}

	return 0;
}