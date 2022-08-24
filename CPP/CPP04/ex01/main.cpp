#include "Cat.hpp"
#include "Dog.hpp"

void test_normal(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Dog a;
	Dog b;
	Dog c(a);

	b = a;
	std::cout << "====== Deep copy check =======" << std::endl;
	std::cout << "Dog <a> idea[5] : " << a.getBrain()->getIdea(5) << std::endl;
	std::cout << "Dog <b> idea[5] : " << b.getBrain()->getIdea(5) << std::endl;
	std::cout << "Dog <c> idea[5] : " << c.getBrain()->getIdea(5) << std::endl << std::endl;
	a.getBrain()->setIdea(5, "changedData A");
	b.getBrain()->setIdea(5, "changedData B");
	c.getBrain()->setIdea(5, "changedData C");
	std::cout << "Dog <a> idea[5] : " << a.getBrain()->getIdea(5) << std::endl;
	std::cout << "Dog <b> idea[5] : " << b.getBrain()->getIdea(5) << std::endl;
	std::cout << "Dog <c> idea[5] : " << c.getBrain()->getIdea(5) << std::endl;
	std::cout << "==============================" << std::endl;
}

void test_array()
{
	Animal* arr[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = new Cat();
		}
		else if (i % 2 == 1)
		{
			arr[i] = new Dog();
		}
	}

	std::cout << std::endl;
	Dog testDog = *(dynamic_cast<Dog*>(arr[1]));
	std::cout << "====== Dog's brain idea =====" << std::endl << std::endl;
	testDog.getBrain()->printBrain();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete arr[i];
}

int main()
{
	test_normal();
	test_array();
}
