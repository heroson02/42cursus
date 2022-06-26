#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	int count;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		count = strlen(argv[i]);
		for (int j = 0; j < count; j++)
		{
			if (argv[i][j] > 96 && argv[i][j] < 123)
				argv[i][j] -= 32;
			std::cout << argv[i][j];
		}
		if ((i + 1) < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
