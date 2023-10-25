#pragma once
#define CRT_USE_NO_WARNINGS

#include <iostream>
#include <initializer_list>

template <class IntType, size_t length>
class Array
{
private:
	IntType array_[length]{};

public:
	Array() {}
	Array(const std::initializer_list<IntType>& list) 
	{
		if (list.size() != length) 
		{
			throw std::exception("Границы векторов не совпадают");
		}

		std::copy(list.begin(), list.end(), array_);
	}
	Array(const IntType* other, size_t otherLength) 
	{
		if (otherLength != length)
		{
			throw std::exception("Размеры векторов не совпадают");
		}

		memcpy(array_, other, sizeof(IntType) * otherLength);
	}
	Array(const Array& other) 
	{
		memcpy(array_, other.array_, sizeof(IntType) * length);
	}

	void PrintAll() const
	{
		for (size_t i = 0; i < length; i++)
		{
			std::cout << array_[i] << " ";
		}
		std::cout << '\n';

	}
	void PrintByIndex(size_t index) const
	{
		if (index >= length)
		{
			throw std::exception("Индекс выходит за границы вектора");
		}

		std::cout << array_[index] << '\n';
	}

	void operator =(const Array& other) 
	{
		memcpy(array_, other.array_, sizeof(IntType) * length);
	}

	Array operator +(const Array& other) const
	{
		Array<IntType, length> result = *this;
		for (size_t i = 0; i < length; i++)
		{
			result[i] += other[i];
		}

		return result;
	}
	Array operator -(const Array& other) const
	{
		Array<IntType, length> result = *this;
		for (size_t i = 0; i < length; i++)
		{
			result[i] -= other[i];
		}

		return result;
	}

	Array operator *(IntType scalar) const
	{
		Array<IntType, length> result = *this;

		for (size_t i = 0; i < length; i++)
		{
			result[i] *= scalar;
		}

		return result;
	}
	Array operator /(IntType scalar) const
	{
		Array<IntType, length> result = *this;

		for (size_t i = 0; i < length; i++)
		{
			result[i] /= scalar;
		}

		return result;
	}

	IntType operator[](size_t index) const
	{
		if (index >= length)
		{
			throw std::exception("Индекс выходит за границы вектора");
		}

		return array_[index];
	}
	IntType& operator[](size_t index)
	{
		if (index >= length)
		{
			throw std::exception("Индекс выходит за границы вектора");
		}

		return array_[index];
	}
};
