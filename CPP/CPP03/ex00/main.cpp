#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Test");

	a.attack("hero");
	a.takeDamage(10);
	a.beRepaired(2);
}
