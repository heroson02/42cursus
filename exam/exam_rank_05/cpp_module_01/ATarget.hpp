#pragma once

#include <iostream>

class ASpell;

class ATarget
{
protected:
	std::string type;
public:
	ATarget();
	ATarget(std::string _type);
	ATarget(const ATarget &obj);
	ATarget &operator=(const ATarget &obj);
	virtual ~ATarget();

	virtual ATarget *clone() const = 0;
	const std::string &getType() const;
	void getHimBySpell(const ASpell &spell) const;
};

#include "ASpell.hpp"