#include "Data.hpp"

int main()
{
	Data a("Bob", 20, "reading books");

	std::cout << a << std::endl;

	uintptr_t data = serialize(&a);

	Data *b = deserialize(data);
	std::cout << *b;
}
