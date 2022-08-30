#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    std::vector<int>	vec;
	unsigned int		max;
	unsigned int		size;
public:
    Span();
    Span(const Span &obj);
    Span& operator=(const Span &obj);
    Span(unsigned int N);
    ~Span();
    void addNumber(int n);
    
    unsigned int shortestSpan();
    unsigned int longestSpan();

	class OutOfRange : public std::exception
	{
		public:
			const char *what(void) const throw();
	};

	class TooLowElements : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif