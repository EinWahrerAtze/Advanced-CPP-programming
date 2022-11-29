//
//  Big_integer.cpp
//  4.11.2
//
//  Created by Den Fedorov on 13.09.2022.
//

#include <cmath>
#include "Big_integer.h"

using rit = std::string::reverse_iterator;

Big_integer::Big_integer()
{
}

Big_integer::Big_integer(const std::string & s) : _digits{ s }, _sign{ false }
{
	if (*_digits.begin() == '-')
	{
		_sign = true;
	}
}

Big_integer::~Big_integer()
{
}

Big_integer::Big_integer(const Big_integer & object)
{
	_sign = object._sign;
	_digits = object._digits;
}

Big_integer::Big_integer(Big_integer && object) noexcept
{
	_sign = object._sign;
	object._sign = false;
	_digits = object._digits;
	object._digits.clear();
}

auto Big_integer::operator=(const Big_integer & object) -> Big_integer &
{
	if (this == &object)
	{
		return *this;
	}
	else
	{
		_digits.clear();
		_digits = object._digits;
		_sign = object._sign;
		return *this;
	}
}

auto Big_integer::operator=(Big_integer && object) noexcept -> Big_integer &&
{
	if (this == &object)
	{
		return std::move(*this);
	}
	else
	{
		_digits.clear();
		_digits = object._digits;
		object._digits.clear();
		_sign = object._sign;
		return std::move(*this);
	}
}

auto Big_integer::operator+(long long n) -> Big_integer
{
	if (n == 0)
	{
		return Big_integer(*this);
	}
	else
	{
		Big_integer temp(std::to_string(n));
		return *this + temp;
	}
}

auto Big_integer::operator*(long long n) -> Big_integer
{
	if (n == 0)
	{
		return Big_integer("0");
	}
	else if (n == 1 || n == -1) // if this < 0 and n == -1
	{
		if (_sign && n == -1)
		{	// change sign of temporary object to positive
			Big_integer temp(*this);
			temp._sign = false;
			temp._digits.erase(temp._digits.begin());
			return temp;
		}
		else if (n == -1) // if this > 0 and n == -1
		{
			Big_integer temp(*this);
			temp._sign = true;
			temp._digits.insert(temp._digits.begin(), '-');
			return temp;
		}
		else // if this > 0 and n == 1
		{
			return Big_integer(*this);
		}
	}
	else if (std::floor(std::log10(n)) == n) // 1, 10, 100, 1000...
	{
		Big_integer temp(*this);
		temp._digits.append(std::log10(n), '0');

		if (_sign) // this < 0 and n > 0
		{
			temp._digits.insert(temp._digits.begin(), '-');
			return temp;
		}
		else if (n < 0) // this > 0 and n < 0
		{
			temp._digits.insert(temp._digits.begin(), '-');
			return temp;
		}
		else // this < 0 and n < 0 or this > 0 and n > 0
		{
			return temp;
		}
	}
	else
	{
		Big_integer temp(std::to_string(n));
		return *this * temp;
	}
}

auto operator+(Big_integer & lhs, Big_integer & rhs) -> Big_integer
{
	// if overflow
	int carry{ 0 };
	// initialize result object with longer string
	Big_integer result(lhs._digits.size() < rhs._digits.size() ? rhs._digits : lhs._digits);
	// reverse iterator for result string
	rit res_begin{ result._digits.rbegin() };
	// reverse iterator for beginning of shorter string
	rit begin{ lhs._digits.size() < rhs._digits.size() ? lhs._digits.rbegin() : rhs._digits.rbegin() };
	// reverse iterator for ending of shorter string
	rit end{ lhs._digits.size() < rhs._digits.size() ? lhs._digits.rend() : rhs._digits.rend() };

	for (begin; begin != end; ++begin)
	{
		*res_begin += carry + (*begin - 48); // 48 is ASCII code for '0'

		if (*res_begin - 48 > 9) // if overflow
		{
			*res_begin -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		++res_begin;
	}

	if (carry == 1) // if short string is over and overflow presents
	{
		if (res_begin != result._digits.rend())
		{
			for (res_begin; res_begin != result._digits.rend(); ++res_begin)
			{
				*res_begin += carry;

				if (*res_begin - 48 > 9) // if overflow still presents
				{
					*res_begin -= 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
			}

			if (carry != 0) // if result string is over and still overflow
			{
				result._digits.insert(result._digits.begin(), '1');
			}
		}
		else // if result._digits._rbegin() == result._digits._rend()
		{
			result._digits.insert(result._digits.begin(), '1');
		}
	}

	return result;
}

auto operator*(Big_integer & lhs, Big_integer & rhs) -> Big_integer
{
	rit lhs_begin{ lhs._digits.rbegin() };
	rit lhs_end{ lhs._digits.rend() };
	rit rhs_begin{ rhs._digits.rbegin() };
	rit rhs_end{ rhs._digits.rend() };
	Big_integer result;
	Big_integer temp;
	int digit{ 0 }; // temporary variable to store result
	int carry{ 0 }; // if overflow
	int shift{ 0 }; // to imitate multiplication by 10

	for (rhs_begin; rhs_begin != rhs_end; ++rhs_begin)
	{
		for (lhs_begin; lhs_begin != lhs_end; ++lhs_begin)
		{
			digit = carry + (*lhs_begin - 48) * (*rhs_begin - 48);

			if (digit > 9)
			{
				carry = digit;
				digit = digit % 10;
				carry -= digit;
				carry /= 10;
			}
			else
			{
				carry = 0;
			}

			temp._digits.insert(temp._digits.begin(), digit + 48);
		}

		if (lhs_begin == lhs_end && carry != 0)
		{
			temp._digits.insert(temp._digits.begin(), carry + 48);
			carry = 0;
		}

		temp._digits.append(shift, '0'); // insert '0' to the end shift-many times
		++shift;
		result = result + temp;
		temp._digits.clear();
		lhs_begin = lhs._digits.rbegin();
	}

	return result;
}

auto operator<<(std::ostream & os, const Big_integer & object) -> std::ostream &
{
	os << object._digits;
	return os;
}
