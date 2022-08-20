#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
class Data
{
private:
	std::string name;
	int			age;
	std::string hobby;

public:
	Data(void);
	Data(std::string _name, int _age, std::string _hobby);
	Data(const Data &obj);
	Data& operator=(const Data &obj);
	~Data();
};

#endif