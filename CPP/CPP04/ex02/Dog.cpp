#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called." << std::endl;
	type = obj.getType();
	brain = new Brain(*obj.getBrain());
}

Dog& Dog::operator= (const Dog &obj)
{
	type = obj.getType();
	if (brain)
		delete brain;
	brain = new Brain(*obj.getBrain());
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
