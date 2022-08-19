#include "Convert.hpp"

int main(int argc, char **argv)
{
	Convert converter;

	if (argc != 2)
		std::cout << "Put only one argument." << std::endl;
	else
		converter.run(argv[1]);
}