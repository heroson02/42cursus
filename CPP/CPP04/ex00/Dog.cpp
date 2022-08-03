#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &obj)
{
	*this = obj;
}

Dog& Dog::operator= (const Dog &obj)
{
	Animal::operator=(obj);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "bark bark!";
}
