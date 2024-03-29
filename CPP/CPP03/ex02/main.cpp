#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());

	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());

	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());
	
	std::cout << std::endl;
	b.guardGate();
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
	return (0);
}