#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap default constructor. (" << name << ")" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap string constructor. (" << name << ")" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor (" << name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj):ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor. (" << name << ")" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &obj)
{
	ClapTrap::operator=(obj);
	std::cout << "ScavTrap operator = (" << name << ")" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name
		<< " attacks " << target
		<< ", causing " << damage 
		<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}