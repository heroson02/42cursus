#include "Base.hpp"
#include <iostream>

int main()
{
	Base *b = generate();
	Base &c = *generate();

	identify(b);
	std::cout << std::endl;
	identify(c);
}
