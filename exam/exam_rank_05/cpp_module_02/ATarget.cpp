#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(std::string _type) { type = _type; }
ATarget::ATarget(const ATarget &obj) { *this = obj; }
ATarget &ATarget::operator=(const ATarget &obj)
{
	type = obj.type;
	return (*this);
}
ATarget::~ATarget() {}
const std::string &ATarget::getType() const
{
	return (type);
}
void ATarget::getHimBySpell(const ASpell &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}