#include "Span.hpp"

Span::Span() : max(0), size(0)
{
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span& Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		max = obj.max;
		size = obj.size;
		vec.clear();
		std::copy(obj.vec.begin(), obj.vec.end(), vec.begin());
	}
	return (*this);
}

Span::Span(unsigned int N) : max(N), size(0)
{
}

Span::~Span()
{
	vec.clear();
}

void Span::addNumber(int n)
{
	if (size >= max)
		throw OutOfRange();
	vec.push_back(n);
	size++;
}

unsigned int Span::shortestSpan()
{
	if (size < 2)
		throw TooLowElements();
	std::vector<int> ex(vec);
	std::sort(ex.begin(), ex.end());
	
	int min = 2147483647;
	int prev = *ex.begin();
	for (std::vector<int>::iterator iter = ex.begin() + 1; iter != ex.end(); iter++)
	{
		min = std::min(min, *iter - prev);
		prev = *iter;
	}

	return min;
}

unsigned int Span::longestSpan()
{
	if (size < 2)
		throw TooLowElements();
	int smallest = *std::min_element(vec.begin(), vec.end());
	int biggest = *std::max_element(vec.begin(), vec.end());
	return (biggest - smallest);
}

const char *Span::OutOfRange::what(void) const throw()
{
	return ("Size out of range.");
}

const char *Span::TooLowElements::what(void) const throw()
{
	return ("Too low amount of elements.");
}
