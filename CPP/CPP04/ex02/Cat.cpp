#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &obj)
{
	*this = obj;
}

Cat& Cat::operator= (const Cat &obj)
{
	Animal::operator=(obj);
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow ~ " << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (brain);
}
