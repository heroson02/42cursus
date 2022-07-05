#include "Harl.hpp"

Harl::Harl()
{
	lst[0].level = "DEBUG";
	lst[1].level = "INFO";
	lst[2].level = "WARNING";
	lst[3].level = "ERROR";
	lst[0].func = &Harl::debug;
	lst[1].func = &Harl::info;
	lst[2].func = &Harl::warning;
	lst[3].func = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my"
	"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
	"years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	for (int i = 0; i < 5; i++)
	{
		if (level == lst[i].level)
		{
			std::cout << "[" << lst[i].level << "]" << std::endl;
			(this->*lst[i].func)();
			return ;
		}
	}
	return ;
}
