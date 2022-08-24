#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string _name);
	FragTrap(const FragTrap &obj);
	FragTrap& operator=(const FragTrap &obj);
	virtual ~FragTrap();

	void highFivesGuys(void);
};

#endif