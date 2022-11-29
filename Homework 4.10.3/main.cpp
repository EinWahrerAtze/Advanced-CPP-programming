//
//  main.cpp
//  4.10.3
//
//  Created by Den Fedorov on 23.08.2022.
//

#include <iostream>
#include "Unique_ptr.hpp"

class Test
{
public:
	auto output() const -> void
	{
		std::cout << "Using '->' notation!\n";
	}
};

auto make_int(int n) -> Unique_ptr<int>
{
	return Unique_ptr<int>(new int(n));
}

auto main(int argc, const char * argv[]) -> int
{
//	system("clear");

	{
		std::cout << "First block:\n";
		Unique_ptr<int> uptr = make_int(10);
		std::cout << "int = " << *uptr << '\n';
	}

	std::cout << '\n';

	{
		std::cout << "Second block:\n";
		Unique_ptr<int> tmp = std::move(make_int(20));
		std::cout << "int = " << *tmp << '\n';
	}

	std::cout << '\n';

	{
		std::cout << "Third block:\n";
		Unique_ptr<int> uptr = make_int(30);
		std::cout << "int = " << *uptr << '\n';
		int * tmp = uptr.release();
		*tmp = 0;
		std::cout << "now int = " << *tmp << '\n';
		delete tmp;
	}

	std::cout << '\n';

	{
		std::cout << "fourth block:\n";
		Unique_ptr<Test> uptr;
		uptr->output();
	}

	std::cout << '\n';

	{
		const int S = 10;
		std::cout << "Fifth block:\n";
		Unique_ptr<int[]> uptr(new int[S]);

		for (int i = 0; i < S; ++i)
		{
			uptr[i] = i;
			std::cout << uptr[i] << (i == S - 1 ? '\n' : ' ');
		}
	}

	return 0;
}
