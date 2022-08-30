#include "Span.hpp"
#include <iostream>

void normal_test()
{
	Span test(10);

	test.addNumber(1);
	test.addNumber(5);
	test.addNumber(32);
	test.addNumber(43);
	test.addNumber(21);
	test.addNumber(27);
	test.addNumber(123);
	test.addNumber(143);
	test.addNumber(133);
	test.addNumber(113);
	
	std::cout << "Shortest : " << test.shortestSpan() << std::endl;
	std::cout << "Longest : " << test.longestSpan() << std::endl;
}

void	error_test()
{
	Span test(0);

	try
	{
		test.addNumber(123);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		test.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void big_test()
{
	Span test(10000);
	for (int i = 0; i < 10000; i++)
		test.addNumber(i);
	std::cout << "Shortest span : " << test.shortestSpan() << std::endl;
	std::cout << "Longest span : " << test.longestSpan() << std::endl;
}

int main()
{
	std::cout << "===== NORMAL TEST ======" << std::endl;
	normal_test();
	std::cout << "===== ERROR TEST ======" << std::endl;
	error_test();
	std::cout << "===== BIG TEST ======" << std::endl;
	big_test();
}
