#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Put only one argument." << std::endl;
	else
	{
		Convert change(argv[1]);

		change.convert_print();
	}
}