#include "iter.hpp"

int main()
{
	int intArr[] = {0, 1, 2, 3, 4, 5};
	std::string strArr[] = {"hello", "my", "name", "is", "yson"};

	std::cout << "====== INT TEST ======" << std::endl;
	iter(intArr, 6, templatePrint);
	std::cout << std::endl << std::endl;
	std::cout << "====== STRING TEST ======" << std::endl;
	iter(strArr, 5, templatePrint);
}
