#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = gen.begin();
	std::map<std::string, ATarget *>::iterator it_end = gen.end();
	while (it != it_end)
	{
		delete it->second;
		++it;
	}
	gen.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		gen.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}
void TargetGenerator::forgetTargetType(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = gen.find(target);
	if (it != gen.end())	//누수가 나지 않게 할당 해제.
		delete it->second;
	gen.erase(target);
}
ATarget* TargetGenerator::createTarget(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = gen.find(target);
	if (it != gen.end())
		return gen[target];
	return NULL;
}
