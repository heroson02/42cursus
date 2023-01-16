#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class ASpell;
class ATarget;

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &obj);
	Warlock& operator=(const Warlock &obj);
	std::map<std::string, ASpell *> brain;
public:
	Warlock(std::string _name, std::string _title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void	setTitle(const std::string a);
	void	introduce() const;

	void	learnSpell(ASpell *spell);
	void	forgetSpell(std::string spell);
	void	launchSpell(std::string spell, ATarget &target);
};
