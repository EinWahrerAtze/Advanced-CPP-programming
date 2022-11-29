#include <iostream>
// link error: <template.h> instead of "SomeClass.h"
#include <SomeClass.h>

int main()
{
	// syntax error: "<" instead of "<<"
	std::cout < "Hello world!\n";

	// semntic error: endless cycle because "++i" operator is missing in the while loop
	int i = 0;

	while (i <= 5)
	{
		std::cout << "Endless loop!\n";
//		++i;
	}

	// compile-time error: number of passed arguments greater than array size S (look into "SomeClass.h")
	SomeClass<int, 5> someclass(1, 2, 3, 4, 5, 6);

	// run-time error: front() tries to access empty string
	std::string somestring;
	somestring.front();

	return 0;
}