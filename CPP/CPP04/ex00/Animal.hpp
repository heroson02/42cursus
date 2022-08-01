#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:
	std::string type;
	std::string sound;
public:
	Animal(void);
	Animal(const Animal &obj);
	Animal& operator= (const Animal &obj);
	~Animal();

	virtual void	makeSound();
};

#endif