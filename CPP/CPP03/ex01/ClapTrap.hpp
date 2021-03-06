#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string name;
    int			health;
    int			energy;
    int			damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &obj);
	ClapTrap& operator= (const ClapTrap &obj);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int	getDamage();
};

#endif