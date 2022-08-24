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
	type = obj.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

std::string		Animal::getType() const
{
	return (type);
}
