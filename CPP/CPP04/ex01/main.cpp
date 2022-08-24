#include "Cat.hpp"
#include "Dog.hpp"

void test_normal(void)
{
	const Animal* i = new Cat();
  	const Animal* j = new Dog();

	const Animal* c = i;
  	std::cout << std::endl;
  	i->makeSound();
  	j->makeSound();

	const Cat* i_cat = dynamic_cast<const Cat*>(i);
	const Cat* c_cat = dynamic_cast<const Cat*>(c);

	std::cout << "i cat idea : " << i_cat->getBrain()->getIdea(5) << std::endl;
	i_cat->getBrain()->setIdea(5, "hello");
	std::cout << "i cat idea : " << i_cat->getBrain()->getIdea(5) << std::endl;
	std::cout << "c cat idea : " << c_cat->getBrain()->getIdea(5) << std::endl;

  	std::cout << std::endl;
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
	Dog *testDog = dynamic_cast<Dog*>(arr[1]);
	std::cout << "====== Dog's brain idea =====" << std::endl << std::endl;
	testDog->getBrain()->printBrain();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete arr[i];
}

int main()
{
	test_normal();
	// test_array();
}
