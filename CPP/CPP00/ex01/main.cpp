#include "PhoneBook.hpp"

int main()
{
	std::string	input;
	PhoneBook	book;

	while (getline(std::cin, input))
	{
		if (!input.compare("ADD"))
		{
			book.add();
		}
		else if (!input.compare("SEARCH"))
		{
			book.search();
		}
		else if (!input.compare("EXIT"))
			exit(0);
	}
}
