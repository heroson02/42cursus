#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
	BrickWall();
	~BrickWall();
	virtual ATarget *clone() const;
};

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

ATarget *BrickWall::clone() const
{
	return (new BrickWall());
}