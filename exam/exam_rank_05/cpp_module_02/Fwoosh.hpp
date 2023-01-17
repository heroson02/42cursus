#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell 
{
public:
	Fwoosh();
	~Fwoosh();
	virtual ASpell *clone() const;
};

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}
