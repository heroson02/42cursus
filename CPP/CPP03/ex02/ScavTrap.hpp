#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap(void);
	ScavTrap(std::string _name);
	~ScavTrap();
	ScavTrap(const ScavTrap &obj);
	ScavTrap& operator= (const ScavTrap &obj);

	void guardGate(void);
	void attack(const std::string &target);
};

#endif