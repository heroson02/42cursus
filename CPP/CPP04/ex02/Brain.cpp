#include "Brain.hpp"

Brain::Brain(void)
{
	std::stringstream ssInt;

	for (int i = 0; i < 100; i++)
	{
		ssInt.str("");
		ssInt << i + 1;
		ideas[i] = "idea " + ssInt.str();
	}
	
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator= (const Brain &obj)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.getIdea(i);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	return (ideas[i]);
}

void Brain::setIdea(int i, std::string data)
{
	ideas[i] = data;
}

void	Brain::printBrain()
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << ideas[i] << std::endl;
	}
}
