//
//  Array.hpp
//  4.5.2
//
//  Created by Den Fedorov on 04.09.2022.
//

#pragma once
#include <stdexcept>

template<typename T, std::size_t S>
class Array
{
public:
	auto operator[](int n) -> T &;
	auto operator[](int n) const -> T;
private:
	T arr[S];
};

template<typename T, std::size_t S>
auto Array<T, S>::operator[](int n) -> T &
{
	if (n < 0 || n >= S)
	{
		throw std::invalid_argument("Wrong index!\n");
	}
	else
	{
		return arr[n];
	}
}

template<typename T, std::size_t S>
auto Array<T, S>::operator[](int n) const -> T
{
	if (n < 0 || n >= S)
	{
		throw std::invalid_argument("Wrong index!\n");
	}
	else
	{
		return arr[n];
	}
}
