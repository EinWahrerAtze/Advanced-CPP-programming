//
//  Matrix.hpp
//  4.5.2
//
//  Created by Den Fedorov on 04.09.2022.
//

#pragma once
#include <stdexcept>

template <typename T>
class Matrix
{
public:
	Matrix(int rows, int columns);
	~Matrix();

	class Row
	{
	public:
		friend class Matrix;
		auto operator[](int n) -> T &;
		auto operator[](int n) const -> const T &;
	private:
		Row(Matrix * ptr, int index, int size);
		int _size;
		int _index;
		Matrix * _array = nullptr;
	};

	auto operator[](int index) -> Row;
	auto operator[](int index) const -> Row;
	auto size() const -> int;
private:
	int _rows;
	int _columns;
	T ** _matrix = nullptr;
};

template<typename T>
Matrix<T>::Matrix(int rows, int columns) : _rows{ rows }, _columns{ columns }
{
	if (_rows < 0 || _columns < 0)
	{
		throw std::invalid_argument("Negative size not allowed!");
	}

	_matrix = new T * [_rows];

	for (int i = 0; i < _rows; ++i)
	{
		_matrix[i] = new T[_columns];
	}

	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _columns; ++j)
		{
			_matrix[i][j] = (i + 1) * (j + 1);
		}
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < _rows; ++i)
	{
		delete[] _matrix[i];
	}

	delete[] _matrix;
}

template<typename T>
auto Matrix<T>::size() const -> int
{
	return _rows * _columns;
}

template<typename T>
auto Matrix<T>::operator[](int index) -> Row
{
	if (index < 0 || index >= _rows)
	{
		throw std::invalid_argument("Wrong index!");
	}
	else
	{
		return Row(this, index, _columns);
	}
}

template<typename T>
auto Matrix<T>::operator[](int index) const -> Row
{
	if (index < 0 || index >= _rows)
	{
		throw std::invalid_argument("Wrong index!");
	}
	else
	{
		return Row(this, index, _columns);
	}
}

template<typename T>
Matrix<T>::Row::Row(Matrix * ptr, int index, int size) : _array{ ptr }, _index{ index }, _size{ size } { }

template<typename T>
auto Matrix<T>::Row::operator[](int n) -> T &
{
	if (n < 0 || n >= _size)
	{
		throw std::invalid_argument("Wrong index!");
	}
	else
	{
		return _array->_matrix[_index][n];
	}
}

template<typename T>
auto Matrix<T>::Row::operator[](int n) const -> const T &
{
	if (n < 0 || n >= _size)
	{
		throw std::invalid_argument("Wrong index!");
	}
	else
	{
		return _array->_matrix[_index][n];
	}
}
