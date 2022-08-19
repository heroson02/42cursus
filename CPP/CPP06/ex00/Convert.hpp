#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cstdlib>

class Convert
{
private:
	Convert(void);
	double val;
public:
	Convert(char *str);
	Convert(const Convert &obj);
	Convert& operator=(const Convert &obj);
	~Convert();

	void	run(const char *str);
};

#endif