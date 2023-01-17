#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = book.begin();
	std::map<std::string, ASpell *>::iterator it_end = book.end();
	while (it != it_end)
	{
		delete it->second;
		it++;
	}
	book.clear();
}
void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}
void	SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = book.find(spell);
	if (it != book.end())	//누수가 나지 않게 할당 해제.
		delete it->second;
	book.erase(spell);
}
ASpell	*SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = book.find(spell);
	if (it != book.end())
		return book[spell];
	return NULL;
}