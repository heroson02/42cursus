#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	brain = new Brain;
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
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "bark bark!" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (brain);
}
