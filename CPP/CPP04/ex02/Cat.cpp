#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = obj;
}

Cat& Cat::operator= (const Cat &obj)
{
	type = obj.getType();
	brain = new Brain(*obj.getBrain());
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
