//
//  Print_container.hpp
//  4.8.2
//
//  Created by Den Fedorov on 06.09.2022.
//

#pragma once
#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>

// template for std::vector, std::list, std::set and std::string
template<template <typename ...> typename Container, typename Type>
auto print_container(const Container<Type> & container) -> void
{
	// determine type of passed container
	if constexpr (std::is_same_v<Container<Type>, std::vector<Type>>)
	{
		std::cout << "std::vector";
	}
	else if constexpr (std::is_same_v<Container<Type>, std::list<Type>>)
	{
		std::cout << "std::list";
	}
	else if constexpr (std::is_same_v<Container<Type>, std::set<Type>>)
	{
		std::cout << "std::set";
	}
	else
	{
		std::cout << "std::string";
	}
	// determine type of container holds
	if constexpr (std::is_same_v<Type, int>)
	{
		std::cout << "<int>\n";
	}
	else if constexpr (std::is_same_v<Type, double>)
	{
		std::cout << "<double>\n";
	}
	else if constexpr (std::is_same_v<Type, std::string>)
	{
		std::cout << "<std::string>\n";
	}
	else
	{
		std::cout << "<char>\n";
	}
	// display the content
	for (const auto & t : container)
	{
		std::cout << t << ' ';
	}

	std::cout << std::endl;
}
// overload for std::array
template<typename Type, std::size_t S>
auto print_container(const std::array<Type, S> & a) -> void
{
	std::cout << "std::array";

	if constexpr (std::is_same_v<Type, int>)
	{
		std::cout << "<int>\n";
	}
	else if constexpr (std::is_same_v<Type, double>)
	{
		std::cout << "<double>\n";
	}
	else if constexpr (std::is_same_v<Type, std::string>)
	{
		std::cout << "<std::string>\n";
	}
	else
	{
		std::cout << "<other>\n";
	}

	for (int i = 0; i < S; ++i)
	{
		std::cout << i << ' ';
	}

	std::cout << std::endl;
}
// overload for std::map
template<typename Key, typename Value>
auto print_container(const std::map<Key, Value> & m) -> void
{
	std::cout << "std::map";

	if constexpr (std::is_same_v<Key, char>)
	{
		std::cout << "<char, ";
	}
	else if constexpr (std::is_same_v<Key, std::string>)
	{
		std::cout << "<std::string, ";
	}
	else
	{
		std::cout << "<other, ";
	}

	if constexpr (std::is_same_v<Value, int>)
	{
		std::cout << "int>\n";
	}
	else if constexpr (std::is_same_v<Value, float>)
	{
		std::cout << "float>\n";
	}
	else
	{
		std::cout << "other>\n";
	}

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		std::cout << '[' << it->first << "] = " << it->second << '\n';
	}
}
