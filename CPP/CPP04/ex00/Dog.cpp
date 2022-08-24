#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = obj;
}

Dog& Dog::operator= (const Dog &obj)
{
	type = obj.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "bark bark!" << std::endl;
}
