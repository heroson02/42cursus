#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
	Fireball();
	~Fireball();
	virtual ASpell *clone() const;
};

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

ASpell *Fireball::clone() const
{
	return (new Fireball());
}
