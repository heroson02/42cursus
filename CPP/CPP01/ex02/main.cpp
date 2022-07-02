#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory of str	:	" << &str << std::endl;
	std::cout << "memory of stringPTR:	" << stringPTR << std::endl;
	std::cout << "memory of stringREF:	" << &stringREF << std::endl;

	std::cout << "value of str:		" << str << std::endl;
	std::cout << "value of stringPTR:	" << *stringPTR << std::endl;
	std::cout << "value of stringREF:	" << stringREF << std::endl;
}
