#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	
	Dog *a;
	Cat *b;

	a = new Dog();
	b = new Cat();
	a->getBrain()->printBrain();
	delete j;//should not create a leak
	delete i;
	delete a;
	delete b;
	while(1)
		;
	return 0;
}

