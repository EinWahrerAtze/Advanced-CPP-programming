//
//  main.cpp
//  4.5.2
//
//  Created by Den Fedorov on 03.09.2022.
//

#include <iostream>
#include "Array.hpp"
#include "Matrix.hpp"

auto main(int argc, const char * argv[]) -> int
{
//------------recursive realization------------
	const int rows{ 10 };								// table dimension
	const int columns{ 10 };							//
	const int row_index{ 4 };							// element to find
	const int column_index{ 6 };						//

	Array<Array<int, columns>, rows> two_dim_array;		// two dimensional array

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			two_dim_array[i][j] = (i + 1) * (j + 1);
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout.width(2);
			std::cout << two_dim_array[i][j] << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << "\ntable at [" << row_index << "][" << column_index << "] = ";

	try
	{
		std::cout << two_dim_array[row_index][column_index];
	}
	catch (const std::invalid_argument & ex)
	{
		std::cout << ex.what();
	}

//--------------realization as required--------------

	std::cout << "\n-----------------------------\n";

	Matrix<int> matrix(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout.width(2);
			std::cout << matrix[i][j] << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << "\ntable at [" << row_index << "][" << column_index << "] = ";

	try
	{
		std::cout << matrix[row_index][column_index];
	}
	catch (const std::invalid_argument & ex)
	{
		std::cout << ex.what();
	}

	std::cout << "\ntable size: " << matrix.size() << std::endl;

	return 0;
}
