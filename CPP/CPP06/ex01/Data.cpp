#include "Data.hpp"

Data::Data(void)
{
	name = "";
	age = 0;
	hobby = "";
}

Data::Data(std::string _name, int _age, std::string _hobby)
{
	name = _name;
	age = _age;
	hobby = _hobby;
}

Data::Data(const Data &obj)
{
	*this = obj;
}

Data& Data::operator=(const Data &obj)
{
	name = obj.name;
	age = obj.age;
	hobby = obj.hobby;
	return (*this);
}

Data::~Data()
{
}

std::string Data::getName() const
{
	return (name);
}

int 		Data::getAge() const
{
	return (age);
}

std::string Data::getHobby() const
{
	return (hobby);
}

std::ostream& operator<<(std::ostream &out, const Data &obj)
{
	out << "address : " << &obj << std::endl
	<< "name : " << obj.getName() << std::endl
	<< "age : " << obj.getAge() << std::endl
	<< "hobby : " << obj.getHobby() << std::endl;
	return (out);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
