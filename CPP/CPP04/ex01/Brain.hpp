#ifndef BRAIN_CPP
#define BRAIN_CPP
#include <iostream>

class Brain
{
public:
	std::string ideas[100];
	
	Brain(void);
	Brain(const Brain &obj);
	Brain& operator= (const Brain &obj);
	~Brain();
};

#endif