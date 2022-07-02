#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie				*zombies;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << i;
		zombies[i].giveName(name + ss.str());
	}
	return (zombies);
}
