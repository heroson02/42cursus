#include "HumanB.hpp"

HumanB::HumanB(std::string name_)
{
	name = name_;
	weapon = NULL;
};

HumanB::~HumanB(){}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon_)
{
	weapon = &weapon_;
}
