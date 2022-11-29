//
//  main.cpp
//  4.5.3
//
//  Created by Den Fedorov on 04.09.2022.
//

#include <iostream>
#include <array>

template<typename T>
struct func
{
public:
	func() : _sum{ 0 }, _count{ 0 } { }
	auto operator()(const T & t) -> void
	{
		if (t % 3 == 0)
		{
			_sum += t;
			++_count;
		}
	}
	auto get_sum() const -> T
	{
		return _sum;
	}
	auto get_count() const -> int
	{
		return _count;
	}
private:
	T _sum;
	int _count;
};

auto main(int argc, const char * argv[]) -> int
{
	std::array<int, 6> arr{ 4, 1, 3, 6, 25, 54 };
	func<int> f;

	for (const auto & n : arr)
	{
		f.operator()(n);
	}

	std::cout << "sum = " << f.get_sum() << std::endl;
	std::cout << "count = " << f.get_count() << std::endl;

	return 0;
}
