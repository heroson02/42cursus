#include "Warlock.hpp"

Warlock::Warlock(std::string _name, std::string _title)
{
	name = _name;
	title = _title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (name);
}
const std::string &Warlock::getTitle() const
{
	return (title);
}
void	Warlock::setTitle(const std::string a)
{
	title = a;
}

void	Warlock::introduce() const	//함수명 뒤에 const를 붙이면 해당 함수 내에서는 해당 클래스의 멤버 변수를 수정할 수 없다는 뜻이다. 멤버 함수가 아니면 해당 키워드를 쓸 수 없다.
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
	//<NAME>: I am <NAME>, <TITLE>!
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		brain.insert(std::pair<std::string, ASpell *>(spell->getName(), spell));
}

void	Warlock::forgetSpell(std::string spell)
{
	std::map<std::string, ASpell *>::iterator it = brain.find(spell);
	if (it != brain.end())	//누수가 나지 않게 할당 해제.
		delete it->second;
	brain.erase(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator it = brain.find(spell);
	if (it != brain.end())	//누수가 나지 않게 할당 해제.
		it->second->launch(target);
}

/*
* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.
*/