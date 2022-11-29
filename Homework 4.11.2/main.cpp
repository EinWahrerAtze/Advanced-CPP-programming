//
//  main.cpp
//  4.11.2
//
//  Created by Den Fedorov on 13.09.2022.
//

#include <iostream>
#include "Big_integer.h"

auto main(int argc, const char * argv[]) -> int
{
//	system("clear");

	Big_integer one("114575");
	Big_integer two("78524");
	Big_integer three("999999999999999999");

	std::cout << one << " + " << two << " = " << one + two << '\n';
	std::cout << one << " + " << three << " = " << one + three << '\n';

	return 0;
}
