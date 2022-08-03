#ifndef WrongCAT_HPP
#define WrongCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &obj);
	WrongCat& operator= (const WrongCat &obj);
	~WrongCat();

	void	makeSound() const;
};

#endif