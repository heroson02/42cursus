#include "Animal.hpp"

Animal::Animal(void)
{
	type = "";
	sound = "";
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &obj)
{
	*this = obj;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator= (const Animal &obj)
{
	type = obj.type;
	sound = obj.sound;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

void	Animal::makeSound()
{
	std::cout << sound << " " << sound << std::endl;
}
