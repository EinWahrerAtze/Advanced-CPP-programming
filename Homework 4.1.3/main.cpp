
//
//  main.cpp
//  4.1.3
//
//  Created by Den Fedorov on 15.08.2022.
//

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

auto clear()->void
{
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}

auto check_input(const std::string & s)->int
{
	if (s.begin() == s.end())
	{
		return -1;
	}
	else if (std::isalpha(s.front()))
	{
		char ch = toupper(s.front());

		if (ch == 'X' || ch == 'C')
		{
			return ch;
		}
		else
		{
			return -1;
		}
	}
	else if (std::isdigit(s.front()))
	{
		int n{0};

		try
		{
			n = std::stoi(s);
		}
		catch (std::out_of_range const & ex)
		{
			std::cout << ex.what();
		}

		return n;
	}
	else
	{
		return -1;
	}
}

auto convert(std::vector<int> angles, std::vector<std::function<void(float)>> functions)->void
{
	for (const auto & angle : angles)
	{
		std::cout << angle << ":\t";
		for (const auto & function : functions)
		{
			function(angle);
		}
		std::cout << '\n';
	}
}

auto main(int argc, const char * argv[])->int
{
#if defined(__APPLE__)
	clear();
#endif
	const float fl{3.1415926 / 180};
	std::vector<int>angles{0, 30, 60, 90};
	std::vector<std::function<void(float)>> functions;
	auto sin{[&fl](int n)
		{
			std::cout << "sin = " << std::sin(n * fl) << " ";

		}};
	auto cos{[&fl](int n)
		{
			std::cout << "cos = " << std::cos(n * fl) << " ";

		}};

	functions.push_back(sin);
	functions.push_back(cos);

	int n{0};
	int prec{0};
	std::string input;

	std::cout.setf(std::ios_base::fixed);

	while (true)
	{
		std::cout.precision(prec);
		std::cout << "Precison: " << prec << ", 'X' to exit, 'C' to change precision.\n\n";
		convert(angles, functions);
		std::cout << "\nNew degree value: ";
		getline(std::cin, input);

		switch (check_input(input))
		{
			case 'C':
			{
				std::cout << "New precision: ";

				getline(std::cin, input);
				prec = check_input(input);
				clear();
				break;
			}
			case 'X':
			{
				clear();
				std::cout << "Bye!\n";
				exit(EXIT_SUCCESS);
			}
			case -1:
			{
				clear();
				std::cout << "Wrong input!\n";
				break;
			}
			default:
			{
				n = check_input(input);

				if (n < 0 || n > 360)
				{
					clear();
					std::cout << "Degree value must be above 0 and less than 360\n";
					break;
				}
				else
				{
					angles.push_back(n);
					clear();
					break;
				}
			}
		}
	}

	return 0;
}