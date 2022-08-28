#include "Convert.hpp"

Convert::Convert(void) {}

Convert::Convert(char *str) : error(false), val(0)
{
	char *ptr = NULL;
	
	val = strtod(str, &ptr);
	if (val == 0 && (str[0] != '+' && str[0] != '-' && !std::isdigit(str[0])))
		error = true;
	if (*ptr && strcmp(ptr, "f"))
		error = true;
}

Convert::Convert(const Convert &obj)
{
	*this = obj;
}

Convert& Convert::operator=(const Convert &obj)
{
	val = obj.val;
	error = obj.error;
	return (*this);
}

Convert::~Convert()
{}

char	Convert::toChar()
{
	return static_cast<char>(val);
}

int	Convert::toInt()
{
	return static_cast<int>(val);
}

float	Convert::toFloat()
{
	return static_cast<float>(val);
}

double	Convert::toDouble()
{
	return static_cast<double>(val);
}

void Convert::printChar()
{
	std::cout << "char : ";
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char b = toChar();
	if (isprint(b))
	{
		std::cout << "'" << b << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

void Convert::printInt()
{
	std::cout << "int : ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible" << std::endl;
	else
		std::cout << toInt() << std::endl;
}

void Convert::printFloat()
{
	std::cout << "float : ";
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << std::showpos << toFloat() << "f" << std::endl;
		return ;
	}
	if (toFloat() == static_cast<int64_t>(toFloat()))
		std::cout << toFloat() << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << toFloat() << "f" << std::endl;
}

void Convert::printDouble()
{
	std::cout << "double : ";
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << std::showpos << toDouble() << std::endl;
		return ;
	}
	if (toDouble() == static_cast<int64_t>(toDouble()))
		std::cout << toDouble() << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << toDouble() << std::endl;
}


void	Convert::convert_print()
{
	if (error == true)
	{
		std::cout << "Convert error" << std::endl;
		return ;
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}
