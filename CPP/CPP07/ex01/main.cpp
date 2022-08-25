#include <iostream>
#include "iter.hpp"

void	intTest(int a)
{
	std::cout << "Number : " << a << std::endl;
}

void	stringTest(std::string a)
{
	std::cout << "String : " << a << std::endl;
}

int main()
{
	int intArr[] = {0, 1, 2, 3, 4, 5};
	std::string strArr[] = {"hello", "my", "name", "is", "yson"};

	std::cout << "====== INT TEST ======" << std::endl;
	iter(intArr, 6, intTest);
	std::cout << std::endl << std::endl;
	std::cout << "====== STRING TEST ======" << std::endl;
	iter(strArr, 5, stringTest);
}
