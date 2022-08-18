#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		line;
	size_t			nPos;

	if (argc != 4)
	{
		std::cout << "Error : argument needs filename and two string." << std::endl; 
		return (1);
	}
	std::string		filename(argv[1]);
	std::string		target(argv[2]);
	std::string		replace(argv[3]);
	input.open(filename);
	if (input.fail())
	{
		std::cout << "Error : can't open file." << std::endl; 
		return (1);
	}
	output.open(filename + ".replace");
	if (output.fail())
	{
		std::cout << "Error : can't make file." << std::endl; 
		return (1);
	}
	while (1)
	{
		std::getline(input, line);
		while (1)
		{
			nPos = line.find(target, 0);
			if (nPos == std::string::npos)
			{
				output << line;
				break ;
			}
			else
			{
				output << line.substr(0, nPos) << replace;
				line = line.substr(nPos + target.length());
			}
		}
		if (input.eof())
			break ;
		output << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
