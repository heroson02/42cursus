#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string name)
{
	type = name;
}

Weapon::~Weapon(){}

const std::string &Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string name)
{
	type = name;
}
