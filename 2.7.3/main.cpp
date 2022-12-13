//
//  main.cpp
//  4.7.3
//
//  Created by Den Fedorov on 06.09.2022.
//

#include <string>
#include "Vector.hpp"

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
	std::cout << "'A' add a new element to vector one\n";
	std::cout << "'S' add a new element to vector one at index\n";
	std::cout << "'E' get an element at index of vector one\n";
	std::cout << "'R' remove element of vector one\n";
	std::cout << "'F' fit vector one to actual size\n";
	std::cout << "'C' copy\n";
	std::cout << "'V' move\n";
	std::cout << "'D' clear vector two\n";
	std::cout << "'X' exit\n\n";
	std::cout << "Input: ";
}

auto main(int argc, const char * argv[]) -> int
{
	clear();
	char ch{ '0' };
	Vector<int> vector_one(16);

	for (int i = 0; i < 15; ++i)
	{
		vector_one.push_back(rand() % 20 + 1);
	}

	Vector<int> vector_two(vector_one);

	while (true)
	{
		std::cout << "Vector one (S = " << vector_one.size();
		std::cout << ", C = " << vector_one.capacity() << "):\n";
		vector_one.print();
		std::cout << "\nVector two (S = " << vector_two.size();
		std::cout << ", C = " << vector_two.capacity() << "):\n";
		vector_two.print();
		menu();
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
					vector_one.push_back(n);
					clear();
					std::cout << std::to_string(n) << " added to the end of vector one\n\n";
				}
				catch (const std::exception & ex)
				{
					std::cout << ex.what();
				}

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
					vector_one.insert(index, element);
					std::cout << std::to_string(element);
					std::cout << " added to vector one at index ";
					std::cout << std::to_string(index) << '\n' << '\n';
				}
				catch (const std::runtime_error & ex)
				{
					std::cout << ex.what();
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
					std::cout << "Element at index " << std::to_string(index) << " is ";
					std::cout << std::to_string(vector_one[index]) << '\n' << '\n';
				}
				catch (const std::runtime_error & ex)
				{
					std::cout << ex.what();
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
					vector_one.remove(index);
					std::cout << "Element at index ";
					std::cout << std::to_string(index) << " removed\n\n";
				}
				catch (const std::runtime_error & ex)
				{
					std::cout << ex.what();
				}

				continue;
			}
			case 'f':
			case 'F':
			{
				clear();
				vector_one.fit();
				std::cout << "Capacity of vector one has been set to its size\n\n";
				continue;
			}
			case 'c':
			case 'C':
			{
				clear();
				std::cout << "Vector one:\n";
				vector_one.print();
				std::cout << "\nVector two:\n";
				vector_two.print();

				int index = 0;
				std::cout << "\n1 - copy vector one to vector two\n";
				std::cout << "2 - copy vector two to vector one\n\n";
				std::cout << "Input: ";
				check(index);

				switch (index)
				{
					case 1:
					{
						clear();
						vector_two = vector_one;
						continue;
					}
					case 2:
					{
						clear();
						vector_one = vector_two;
						continue;
					}
					default:
					{
						std::cout << "Wrong input!\n";
						continue;
					}
				}
			}
			case 'v':
			case 'V':
			{
				clear();
				int index = 0;
				std::cout << "Vector one:\n";
				vector_one.print();
				std::cout << "\nVector two:\n";
				vector_two.print();
				std::cout << "\n1 - move vector one to vector two\n";
				std::cout << "2 - move vector two to vector one\n\n";
				std::cout << "Input: ";
				check(index);

				switch (index)
				{
					case 1:
					{
						clear();
						vector_two = std::move(vector_one);
						continue;
					}
					case 2:
					{
						clear();
						vector_one = std::move(vector_two);
						continue;
					}
					default:
					{
						std::cout << "Wrong input!\n";
						continue;
					}
				}
			}
			case 'd':
			case 'D':
			{
				clear();
				vector_two.clear();
				std::cout << "Done\n\n";
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
				std::cout << "Wrong input!\n\n";
				continue;
			}
		}
	}

	return 0;
}
