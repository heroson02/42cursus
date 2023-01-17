#pragma once

#include "ATarget.hpp"
#include <map>
#include <iostream>

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator &obj);
public:
	TargetGenerator();
	~TargetGenerator();
	
	std::map<std::string, ATarget *> gen;
	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const &target);
	ATarget* createTarget(std::string const &target);
};
