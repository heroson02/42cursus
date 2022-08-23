#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string		name;
    unsigned int	health;
    unsigned int	energy;
    unsigned int	damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &obj);
	ClapTrap& operator= (const ClapTrap &obj);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int	getDamage() const;
	unsigned int	getHealth() const;
	unsigned int	getEnergy() const;
};

#endif