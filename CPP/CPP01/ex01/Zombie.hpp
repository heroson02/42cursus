#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <sstream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	~Zombie();
	void	announce(void);
	void	giveName(std::string name_);
};

Zombie* zombieHorde( int N, std::string name );

#endif