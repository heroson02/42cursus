#pragma once

#include "ASpell.hpp"
#include <map>
#include <iostream>

class SpellBook
{
private:
	std::map<std::string, ASpell *> book;
	SpellBook(const SpellBook& obj);
	SpellBook &operator=(const SpellBook& obj);
public:
	SpellBook();
	~SpellBook();
	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string const &spell);
	ASpell	*createSpell(std::string const &spell);
};
