#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip> 

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

	void	convert_print();
	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();

	char	toChar();
	int	toInt();
	float	toFloat();
	double	toDouble();
};

#endif