#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

class Convert
{
private:
	Convert(void);
	bool error;
	double val;
public:
	Convert(char *str);
	Convert(const Convert &obj);
	Convert& operator=(const Convert &obj);
	~Convert();

	void	run(const char *str);
	void	convert_print();
	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();
};

#endif