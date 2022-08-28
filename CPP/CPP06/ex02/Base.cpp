#include "Base.hpp"

Base::~Base()
{}

Base *generate(void)
{
	int i;

	srand((unsigned int)time(NULL));
	i = rand() % 3;
	switch (i)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{}
}
