#include "Data.hpp"

int main()
{
	Data a("yson", 00, "coding");

	std::cout << a << std::endl;

	uintptr_t data = serialize(&a);

	Data *b = deserialize(data);
	std::cout << *b;
}
