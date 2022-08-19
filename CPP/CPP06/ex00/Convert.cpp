#include "Convert.hpp"

Convert::Convert(void) {}

Convert::Convert(char *str)
{
	char *ptr = NULL;
	
	val = strtod(str, &ptr);
}

Convert::Convert(const Convert &obj)
{
	
}

Convert& Convert::operator=(const Convert &obj)
{

}

Convert::~Convert()
{
}

void	Convert::run(const char *str)
{
	
}
