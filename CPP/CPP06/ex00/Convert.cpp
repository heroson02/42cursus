#include "Convert.hpp"

Convert::Convert(void) {}

Convert::Convert(char *str) : error(false), val(0)
{
	char *ptr = NULL;
	
	val = strtod(str, &ptr);
	if (*ptr && strcmp(ptr, "f"))
		error = true;
}

Convert::Convert(const Convert &obj)
{
	if (this != &obj)
	{
		*this = obj;
	}
}

Convert& Convert::operator=(const Convert &obj)
{
	val = obj.val;
	error = obj.error;
	return (*this);
}

Convert::~Convert()
{}

void Convert::toChar()
{
	std::cout << "char : ";
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char b = static_cast<char>(val);
	if (isprint(b))
	{
		std::cout << "'" << b << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

void Convert::toInt()
{
	std::cout << "int : ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;
}

void Convert::toFloat()
{
	(void)val;
}

void Convert::toDouble()
{
	(void)val;
}


void	Convert::convert_print()
{
	if (error == true)
	{
		std::cout << "Convert error" << std::endl;
		return ;
	}
	toChar();
	toInt();
	toFloat();
	toDouble();
}
