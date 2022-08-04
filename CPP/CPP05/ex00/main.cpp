#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("Hero", 1);

	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << b << std::endl;
	b.decreaseGrade();
	std::cout << std::endl;
	std::cout << b << std::endl;
}
