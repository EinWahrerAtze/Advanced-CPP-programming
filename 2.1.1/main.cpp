//
//  main.cpp
//  4.1.1
//
//  Created by Den Fedorov on 15.08.2022.
//

#include <iostream>
#include <array>
#include <algorithm>

auto main(int argc, const char * argv[])->int
{
	const size_t Size{10};
	std::array<int, Size> ar{0};

	auto fill = []()->int
	{
		return rand() % 10 + 1;
	};

	std::generate(ar.begin(), ar.end(), fill);

	for (int i : ar)
	{
		std::cout << i << ' ';
	}

	std::for_each(std::begin(ar), std::end(ar), [](int & i)
	{
		((i & 1) == 1 ? i *= 3 : i);
	});

	std::cout << '\n';

	for (int i : ar)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}