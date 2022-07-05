#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please put only one operation" << std::endl;
		return (0);
	}

	Harl		mark1;
	int			i;
	std::string	input(argv[1]);

	for (i = 0; i < 5; i++)
	{
		if (input == mark1.lst[i].level)
			break ;
	}
	switch (i)
	{
	case 0:
		mark1.complain(0);
	case 1:
		mark1.complain(1);
	case 2:
		mark1.complain(2);
	case 3:
		mark1.complain(3);
		break ;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
