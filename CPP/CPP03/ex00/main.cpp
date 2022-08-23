#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;
	a.beRepaired(2);
	b.beRepaired(5);
	std::cout << std::endl;
	a.takeDamage(10);
	a.beRepaired(1);
}
