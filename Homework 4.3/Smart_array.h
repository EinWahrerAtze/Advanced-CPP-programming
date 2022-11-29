//
//  smart_array.hpp
//  4.3.1
//
//  Created by Den Fedorov on 30.08.2022.
//

#pragma once

template <typename T>
class Smart_array
{
public:
	Smart_array();
	Smart_array(int size);
	Smart_array(int size, T t);
	template<typename... Ts>
	Smart_array(Ts... args);
	~Smart_array();
	Smart_array(const Smart_array & s);
	auto operator[](int index) -> T &;
	auto operator[](int index) const-> const T &;
	Smart_array & operator=(const Smart_array & s);
	auto add(T element) -> void;
	auto insert(int index, T element) -> void;
	auto remove(int index) -> void;
	auto fit() -> void;
	auto clear() -> void;
	auto get_size() const -> int;
	auto get_capacity() const -> int;
	auto print() const -> void;
private:
	int _size;
	int _capacity;
	T * _elements;
};

template<typename T>
Smart_array<T>::Smart_array() : _size{ 0 }, _capacity{ _size }
{
	_elements = new T[_capacity];
}

template<typename T>
Smart_array<T>::Smart_array(int size) : _size{ size }, _capacity{ size + size / 2 }
{
//	_elements = new T[_capacity];		// g++ won't pass it
	_elements = new T[_capacity](0);
}

template<typename T>
Smart_array<T>::Smart_array(int size, T t) : _size{ size }, _capacity{ size + size / 2 }
{
	_elements = new T[_capacity];

	for (int i = 0; i < _size; ++i)
	{
		_elements[i] = t;
	}
}

template<typename T>
Smart_array<T>::Smart_array(const Smart_array & s)
{
	_capacity = s._capacity;
	_size = s._size;
	_elements = new T[_capacity];

	for (int i = 0; i < _size; ++i)
	{
		_elements[i] = s._elements[i];
	}
}

template <typename T>
template<typename... Ts>
Smart_array<T>::Smart_array(Ts... args) : _size{ sizeof... (Ts) }, _capacity{ _size + _size / 2 }
{
	static_assert((std::is_same_v<T, Ts> & ...), "Invalid type of arguments!");
	_elements = new T[_capacity]{ args... };
}

template<typename T>
Smart_array<T>::~Smart_array()
{
	delete[] _elements;
}

template<typename T>
auto Smart_array<T>::operator[](int index) -> T &
{
	if (index > _size - 1 || index < 0)
	{
		throw std::runtime_error("Wrong index!\n");
	}
	else
	{
		return _elements[index];
	}
}

template<typename T>
auto Smart_array<T>::operator[](int index) const -> const T &
{
	if (index > _size - 1 || index < 0)
	{
		throw std::runtime_error("Wrong index!\n");
	}
	else
	{
		return _elements[index];
	}
}

template<typename T>
Smart_array<T> & Smart_array<T>::operator=(const Smart_array & s)
{
	if (this == &s)
	{
		return *this;
	}
	else
	{
		delete[] _elements;
		_size = s._size;
		_capacity = s._capacity;
		_elements = new T[_capacity];

		for (int i = 0; i < _size; ++i)
		{
			_elements[i] = s._elements[i];
		}

		return *this;
	}
}

template<typename T>
auto Smart_array<T>::add(T element) -> void
{
	if (_size == _capacity - 1 || _size == _capacity)
	{
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
auto Smart_array<T>::insert(int index, T element) -> void
{
	if (index > _size || index < 0)
	{
		throw std::runtime_error("Wrong index!\n");
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
auto Smart_array<T>::remove(int index) -> void
{
	if (index > _size || index < 0)
	{
		throw std::runtime_error("Out of range!\n");
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
auto Smart_array<T>::fit() -> void
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
auto Smart_array<T>::clear() -> void
{
	delete[] _elements;
	_size = 0;
	_capacity = 0;
	_elements = nullptr;
}

template<typename T>
auto Smart_array<T>::get_size() const -> int
{
	return _size;
}

template<typename T>
auto Smart_array<T>::get_capacity() const -> int
{
	return _capacity;
}

template<typename T>
auto Smart_array<T>::print() const -> void
{
	for (int i = 0; i < _size; ++i)
	{
		std::cout << _elements[i] << (i == _size - 1 ? '\n' : ' ');
	}
}
