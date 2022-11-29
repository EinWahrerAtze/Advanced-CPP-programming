//
//  Unique_ptr.hpp
//  4.10.3
//
//  Created by Den Fedorov on 08.08.2022.
//

#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Unique_ptr
{
public:
	Unique_ptr();
	Unique_ptr(T * ptr);
	~Unique_ptr();
	Unique_ptr(Unique_ptr && object);
	auto release() -> T*;
	Unique_ptr(const Unique_ptr & object) = delete;
	auto operator=(const Unique_ptr & object)->Unique_ptr & = delete;
	auto operator=(Unique_ptr && object) -> void;
	auto operator*() -> T&;
	auto operator->() -> T*;
private:
	T * _ptr = nullptr;
};

template<typename T>
Unique_ptr<T>::Unique_ptr() : _ptr{ nullptr }
{
	std::cout << "<nullptr object created>\n";
}

template<typename T>
Unique_ptr<T>::Unique_ptr(T * ptr) : _ptr{ ptr }
{
	std::cout << "<object created>\n";
}

template<typename T>
Unique_ptr<T>::~Unique_ptr()
{
	delete _ptr;
	std::cout << "<object deleted>\n";
}

template<typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr && object)
{
	delete _ptr;
	_ptr = object._ptr;
	object._ptr = nullptr;
	std::cout << "<object moved>\n";
}

template<typename T>
auto Unique_ptr<T>::release() -> T*
{
	std::cout << "<object released>\n";
	T * tmp = _ptr;
	_ptr = nullptr;
	return tmp;
}

template<typename T>
auto Unique_ptr<T>::operator=(Unique_ptr && object) -> void
{
	delete _ptr;
	_ptr = object._ptr;
	object._ptr = nullptr;
	std::cout << "<object moved>\n";
}

template<typename T>
auto Unique_ptr<T>::operator*() -> T&
{
	return *(this->_ptr);
}

template<typename T>
auto Unique_ptr<T>::operator->() -> T*
{
	return this->_ptr;
}

template<typename T>
class Unique_ptr<T[]>
{
public:
	Unique_ptr();
	Unique_ptr(T * ptr);
	~Unique_ptr();
	Unique_ptr(Unique_ptr && object);
	auto release() -> T*;
	Unique_ptr(const Unique_ptr & object) = delete;
	auto operator=(const Unique_ptr & object)->Unique_ptr & = delete;
	auto operator=(Unique_ptr && object) -> void;
	auto operator*() -> T&;
	auto operator->() -> T*;
	auto operator[](int n) -> T&;
private:
	T * _ptr = nullptr;
};

template<typename T>
Unique_ptr<T[]>::Unique_ptr() : _ptr{ nullptr }
{
	std::cout << "<array object created>\n";
};

template<typename T>
Unique_ptr<T[]>::Unique_ptr(T * ptr) : _ptr{ ptr }
{
	std::cout << "<array object created>\n";
}

template<typename T>
Unique_ptr<T[]>::~Unique_ptr()
{
	delete[] _ptr;
	std::cout << "<array object deleted>\n";
}

template<typename T>
Unique_ptr<T[]>::Unique_ptr(Unique_ptr && object)
{
	delete[] _ptr;
	_ptr = object._ptr;
	object._ptr = nullptr;
}

template<typename T>
auto Unique_ptr<T[]>::release() -> T*
{
	T * tmp = _ptr;
	_ptr = nullptr;
	return tmp;
}

template<typename T>
auto Unique_ptr<T[]>::operator=(Unique_ptr && object) -> void
{
	delete[] _ptr;
	_ptr = object._ptr;
	object._ptr = nullptr;
}

template<typename T>
auto Unique_ptr<T[]>::operator*() -> T&
{
	return *(this->_ptr);
}

template<typename T>
auto Unique_ptr<T[]>::operator->() -> T*
{
	return this->_ptr;
}

template<typename T>
auto Unique_ptr<T[]>::operator[](int n) -> T&
{
	if (n < 0)
	{
		throw std::invalid_argument("Wrong index!\n");
	}
	else
	{
		return _ptr[n];
	}
}
