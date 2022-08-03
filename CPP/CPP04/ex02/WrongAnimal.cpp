#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	type = "";
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal &obj)
{
	type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "There is no sound yet." << std::endl;
}

std::string		WrongAnimal::getType() const
{
	return (type);
}
