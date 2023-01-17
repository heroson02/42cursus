#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
	Polymorph();
	~Polymorph();
	virtual ASpell *clone() const;
};

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}
