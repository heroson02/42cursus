#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &obj);
	WrongAnimal& operator= (const WrongAnimal &obj);
	virtual ~WrongAnimal();

	void	makeSound() const;
	std::string		getType() const;
};

#endif