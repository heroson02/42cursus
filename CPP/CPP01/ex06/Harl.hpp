#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class	Harl;

typedef struct s_complain
{
	std::string	level;
	void		(Harl::*func)(void);
}	t_complain;

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	t_complain lst[4];
	void complain(int i);
};

#endif