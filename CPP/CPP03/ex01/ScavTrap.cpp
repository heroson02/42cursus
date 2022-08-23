#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "New ScavTrap created." << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "New ScavTrap " << name << " created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap eliminated" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj):ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor. (" << name << ")" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	name = obj.name;
	health = obj.getHealth();
	damage = obj.getDamage();
	energy = obj.getEnergy();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (health < 1)
	{
		std::cout << "ScavTrap " << name << " is already dead." << std::endl;
		return ;
	}
	else if (energy < 1)
	{
		std::cout << "ScavTrap " << name << " has no energy." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name
		<< " attacks " << target
		<< ", causing " << damage 
		<< " points of damage!" << std::endl;
	energy--;
}

void ScavTrap::guardGate(void)
{
	if (health < 1)
	{
		std::cout << "ScavTrap " << name << " is already dead." << std::endl;
		return ;
	}
	else if (energy < 1)
	{
		std::cout << "ScavTrap " << name << " has no energy." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}