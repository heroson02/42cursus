#include "Zombie.hpp"

int main()
{
	Zombie a("firs");
	a.announce();
	Zombie *tester = newZombie("seco");
	tester->announce();
	randomChump("thir");
	delete(tester);
}
