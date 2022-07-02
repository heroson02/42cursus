#include "Zombie.hpp"

Zombie::Zombie(std::string name_)
{
	name = name_;
}

Zombie::~Zombie()
{
	std::cout << name << " zombie is died." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

