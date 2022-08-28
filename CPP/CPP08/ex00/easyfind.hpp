#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

class DataNotFound : public std::exception
{
	public:
		const char *what(void) const throw()
        {
            return "Data not found.";
        }
};

template <typename T>
typename T::iterator easyfind(T arr, int n)
{
    typename T::iterator iter = std::find(std::begin(arr), std::end(arr), n);
    if (iter == std::end(arr))
        throw DataNotFound();
    return (iter);
}

#endif