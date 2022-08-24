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
	if (this != &obj)
	{
		type = obj.getType();
		brain = obj.getBrain();
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "meow ~ " << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (brain);
}
