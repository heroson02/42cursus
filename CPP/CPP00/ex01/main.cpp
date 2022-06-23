#include "phonebook.hpp"

int main()
{
	std::string	input;
	PhoneBook	book;

	while (1)
	{
		std::cin >> input;
		if (!input.compare("ADD"))
		{
			book.add();
		}
		else if (!input.compare("SEARCH"))
		{
			std::cout << "search" << std::endl;
		}
		else if (!input.compare("EXIT"))
			exit(0);
	}
}
