#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
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
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow ~ " << std::endl;
}
