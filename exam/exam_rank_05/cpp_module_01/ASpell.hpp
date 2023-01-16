#ifndef ASPELL_HPP
#define ASPELL_HPP

class ASpell
{
protected:
	std::string name;
	std::string effects;
public:
	ASpell(std::string &_name, std::string &_effects);
	~ASpell();
	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell *clone() = 0;
	void	launch(const *ATarget target);
};

ASpell(std::string &_name, std::string &_effects)
{
}

ASpell::~ASpell()
{
}


#endif