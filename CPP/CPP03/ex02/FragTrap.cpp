#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "New FragTrap created." << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "New FragTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap's copy constructor (" << name << ")" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	name = obj.name;
	health = obj.getHealth();
	energy = obj.getEnergy();
	damage = obj.getDamage();
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap eliminated" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (health < 1)
	{
		std::cout << "FragTrap " << name << " is already dead." << std::endl;
		return ;
	}
	else if (energy < 1)
	{
		std::cout << "FragTrap " << name << " has no energy." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " wants high fives." << std::endl;
}