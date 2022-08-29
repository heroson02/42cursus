#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T	*arr;
	unsigned int	_size;
public:
	Array()
	{
		_size = 0;
		arr = new T[0];
	};

	Array(unsigned int n)
	{
		_size = n;
		arr = new T[n];
	};

	Array(const Array &obj)
	{
		_size = obj.size();
		arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			arr[i] = obj[i];
		}
	};
	
	Array& operator=(const Array &obj)
	{
		if (arr)
			delete []arr;
		_size = obj.size();
		arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			arr[i] = obj[i];
		}
	};

	~Array()
	{
		if (arr)
			delete []arr;
	};
	
	const T& operator[](unsigned int i) const
	{
		if (_size <= i)
			throw SegFault();
		return (arr[i]);
	};

	T& operator[](unsigned int i)
	{
		if (_size <= i)
			throw SegFault();
		return (arr[i]);
	};

	unsigned int	size() const
	{
		return _size;
	};

	class SegFault : public std::exception
	{
		public:
			const char *what(void) const throw()
			{
				return ("Index is out of bound");
			}
	};
};

#endif