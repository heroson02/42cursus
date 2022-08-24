#include "Cat.hpp"
#include "Dog.hpp"

void test_normal(void) {
  const Animal* i = new Cat();
  const Animal* j = new Dog();

  std::cout << std::endl;
  i->makeSound();
  j->makeSound();
  std::cout << std::endl;

  delete j;
  delete i;
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
	test_array();
}
