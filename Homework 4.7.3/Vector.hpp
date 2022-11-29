//
//  Vector.hpp
//  4.7.3
//
//  Created by Den Fedorov on 06.09.2022.
//

#pragma once
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(int size);
	Vector(int size, T t);
	template<typename... Ts>
	Vector(Ts... args);
	~Vector();
	Vector(const Vector & v);
	Vector(const Vector && v) noexcept;
	auto operator[](int index)->T;
	auto operator[](int index) const->T;
	auto operator=(const Vector & v)->Vector &;
	auto operator=(Vector && v) noexcept -> Vector &;
	auto push_back(T element) -> void;
	auto insert(int index, T element) -> void;
	auto remove(int index) -> void;
	auto fit() -> void;
	auto clear() -> void;
	auto size() const -> int;
	auto capacity() const -> int;
	auto empty() const -> bool;
	auto print() const -> void;
private:
	int _size;
	int _capacity;
	T * _elements = nullptr;
};

template<typename T>
Vector<T>::Vector()
{
}

template<typename T>
Vector<T>::Vector(int n) : _size{ 0 }, _capacity{ n }
{
	_elements = new T[_capacity];
}

template<typename T>
Vector<T>::Vector(int n, T t) : _size{ n }, _capacity{ n + n / 2 }
{
	_elements = new T[_capacity];

	for (int i = 0; i < _size; ++i)
	{
		_elements[i] = t;
	}
}

template<typename T>
Vector<T>::Vector(const Vector & v)
{
	_capacity = v._capacity;
	_size = v._size;
	_elements = new T[_capacity];

	for (int i = 0; i < _size; ++i)
	{
		_elements[i] = v._elements[i];
	}

	std::cout << "<copy constructor executed>\n\n";
}

template<typename T>
Vector<T>::Vector(const Vector && v) noexcept
{
	_elements = v._elements;
	v._size = 0;
	v._capacity = 0;
	v._elements = nullptr;

	std::cout << "<move constructor executed>\n\n";
}

template <typename T>
template<typename... Ts>
Vector<T>::Vector(Ts... args) : _size{ sizeof... (Ts) }, _capacity{ _size + _size / 2 }
{
	static_assert((std::is_same_v<T, Ts> & ...), "Invalid type of arguments!");
	_elements = new T[_capacity]{ args... };
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] _elements;
	_elements = nullptr;
}

template<typename T>
auto Vector<T>::operator[](int index) -> T
{
	if (index > _size - 1 || index < 0)
	{
		throw std::runtime_error("Wrong index!\n\n");
	}
	else
	{
		return _elements[index];
	}
}

template<typename T>
auto Vector<T>::operator[](int index) const -> T
{
	if (index > _size - 1 || index < 0)
	{
		throw std::runtime_error("Wrong index!\n\n");
	}
	else
	{
		return _elements[index];
	}
}

template<typename T>
auto Vector<T>::operator=(const Vector & v) -> Vector<T> &
{
	if (this == &v)
	{
		return *this;
	}
	else
	{
		delete[] _elements;
		_size = v._size;
		_capacity = v._capacity;
		_elements = new T[_capacity];

		for (int i = 0; i < _size; ++i)
		{
			_elements[i] = v._elements[i];
		}

		std::cout << "<l-value assignment operator executed>\n\n";

		return *this;
	}
}

template<typename T>
auto Vector<T>::operator=(Vector && v) noexcept -> Vector &
{
	if (this == &v)
	{
		return *this;
	}
	else
	{
		delete[] _elements;
		_size = v._size;
		_capacity = v._capacity;
		_elements = v._elements;
		v._size = 0;
		v._capacity = 0;
		v._elements = nullptr;

		std::cout << "<r-value assignment operator executed>\n\n";

		return *this;
	}
}

template<typename T>
auto Vector<T>::push_back(T element) -> void
{
	if (_size == _capacity - 1 || _size == _capacity)
	{
		if (_size == 0)
		{
			_capacity = 2;
		}

		int new_capacity = _capacity + _capacity / 2;
		T * temp = new T[new_capacity];

		for (int i = 0; i < _size; ++i)
		{
			temp[i] = _elements[i];
		}

		delete[] _elements;
		_capacity = new_capacity;
		_elements = temp;
	}

	_elements[_size] = element;
	++_size;
}

template<typename T>
auto Vector<T>::insert(int index, T element) -> void
{
	if (index > _size || index < 0)
	{
		throw std::runtime_error("Wrong index!\n\n");
	}
	else if (_size == _capacity - 1 || _size == _capacity)
	{
		int new_capacity = _capacity + _capacity / 2;
		T * temp = new T[new_capacity];

		for (int i = 0; i < index; ++i)
		{
			temp[i] = _elements[i];
		}

		temp[index] = element;
		++_size;

		for (int i = index + 1; i < _size; ++i)
		{
			temp[i] = _elements[i - 1];
		}

		delete[] _elements;
		_capacity = new_capacity;
		_elements = temp;
	}
	else
	{
		T * temp = new T[_size - index];

		for (int i = 0; i < _size - index; ++i)
		{
			temp[i] = _elements[i + index];
		}

		++_size;
		_elements[index] = element;

		for (int i = 0; i < _size; ++i)
		{
			_elements[i + index + 1] = temp[i];
		}

		delete[] temp;
	}
}

template<typename T>
auto Vector<T>::remove(int index) -> void
{
	if (index > _size || index < 0)
	{
		throw std::runtime_error("Out of range!\n\n");
	}
	else
	{
		for (int i = index; i < _size; ++i)
		{
			_elements[i] = _elements[i + 1];
		}

		--_size;
	}
}

template<typename T>
auto Vector<T>::fit() -> void
{
	T * temp = new T[_size];

	for (int i = 0; i < _size; ++i)
	{
		temp[i] = _elements[i];
	}

	delete[] _elements;
	_capacity = _size;
	_elements = temp;
}

template<typename T>
auto Vector<T>::clear() -> void
{
	delete[] _elements;
	_size = 0;
	_capacity = 0;
	_elements = nullptr;
}

template<typename T>
auto Vector<T>::size() const -> int
{
	return _size;
}

template<typename T>
auto Vector<T>::capacity() const -> int
{
	return _capacity;
}

template <typename T>
auto Vector<T>::empty() const -> bool
{
	return _size == 0;
}

template<typename T>
auto Vector<T>::print() const -> void
{
	if (this->empty())
	{
		std::cout << "Vector is empty\n";
	}
	else
	{
		for (int i = 0; i < _size; ++i)
		{
			std::cout << _elements[i] << (i == _size - 1 ? '\n' : ' ');
		}
	}
}

