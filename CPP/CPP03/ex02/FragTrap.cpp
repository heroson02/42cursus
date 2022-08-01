#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap's default constructor (" << name << ")" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap's string constructor (" << name << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap's copy constructor (" << name << ")" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout << "FragTrap operator = (" << name << ")" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor (" << name << ")" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " wants high fives." << std::endl;
}