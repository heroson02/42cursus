#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA(std::string name_, Weapon &weapon_);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon &weapon_);
};

#endif