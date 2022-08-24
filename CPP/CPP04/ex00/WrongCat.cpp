#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "Cat";
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator= (const WrongCat &obj)
{
	WrongAnimal::operator=(obj);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "meow ~ ";
}