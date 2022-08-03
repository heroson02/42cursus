#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &obj);
	Dog& operator= (const Dog &obj);
	virtual ~Dog();

	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif