#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
class Span
{
private:
    std::vector vec;
public:
    Span();
    Span(const Span &obj);
    Span& operator=(const Span &obj);
    Span(unsigned int N);
    ~Span();
    void addNumber();
    
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

Span::Span(/* args */)
{
}

Span::~Span()
{
}


#endif