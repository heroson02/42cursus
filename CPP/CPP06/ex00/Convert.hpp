#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cstdlib>

class Convert
{
private:
public:
	Convert();
	Convert(const Convert &obj);
	Convert& operator=(const Convert &obj);
	~Convert();
};

#endif