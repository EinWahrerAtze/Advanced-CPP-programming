//
//  Big_integer.h
//  4.11.2
//
//  Created by Den Fedorov on 13.09.2022.
//

#pragma once
#include <string>
#include <iostream>

class Big_integer
{
public:
	Big_integer();
	Big_integer(const std::string & s);
	~Big_integer();
	Big_integer(const Big_integer & object);
	Big_integer(Big_integer && object) noexcept;
	auto operator=(const Big_integer & object) -> Big_integer &;
	auto operator=(Big_integer && object) noexcept -> Big_integer &&;
	auto operator+(long long n) -> Big_integer;
	auto operator*(long long n) -> Big_integer;
	friend auto operator+(Big_integer & lhs, Big_integer & rhs) -> Big_integer;
	friend auto operator*(Big_integer & lhs, Big_integer & rhs) -> Big_integer;
	friend auto operator<<(std::ostream & os, const Big_integer & object) -> std::ostream &;
private:
	bool _sign;
	std::string _digits;
};
