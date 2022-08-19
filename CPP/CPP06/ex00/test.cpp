#include "Convert.hpp"

int main()
{
	char *ptr = NULL;
	double val = strtod("23424.324fsdfa", &ptr);

	// std::cout.fixed;
	std::cout.precision(10);
	std::cout << val << std::endl;
	std::cout << ptr << std::endl;
}