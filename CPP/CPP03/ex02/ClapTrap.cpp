#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
    name = "";
    health = 10;
    energy = 10;
    damage = 0;
	std::cout << "New ClapTrap created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap eliminated" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
    health = 10;
    energy = 10;
    damage = 0;
	std::cout << "New ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &obj)
{
	name = obj.name;
	health = obj.health;
	energy = obj.energy;
	damage = obj.damage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (health < 1)
	{
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return ;
	}
	else if (energy < 1)
	{
		std::cout << "ClapTrap " << name << " has no energy." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name
		<< " attacks " << target
		<< ", causing " << damage 
		<< " points of damage!" << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (health < 1)
	{
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return ;
	}
	if (health <= amount)
	{
		std::cout << "ClapTrap " << name << " died." << std::endl;
		health = 0;
		return ;
	}
	std::cout << "ClapTrap " << name
		<< " took " << amount
		<< " points of damage!" << std::endl;
	health -= amount;
	std::cout << "ClapTrap " << name << " has "
		<< health << " hit point." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health < 1)
	{
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
		return ;
	}
	else if (energy < 1)
	{
		std::cout << "ClapTrap " << name << " has no energy." << std::endl;
		return ;
	}
	health += amount;
	std::cout << "ClapTrap " << name << " repair himself. " << name << "gets " 
		<< amount << " hit points."<< std::endl;
	energy--;
}

int ClapTrap::getDamage()
{
	return (damage);
}