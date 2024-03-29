#include "Animal.hpp"

Animal::Animal(void)
{
	type = "";
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = obj;
}

Animal& Animal::operator= (const Animal &obj)
{
	type = obj.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "There is no sound yet." << std::endl;
}

std::string		Animal::getType() const
{
	return (type);
}
