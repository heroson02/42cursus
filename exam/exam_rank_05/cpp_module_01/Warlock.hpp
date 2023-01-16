#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &obj);
	Warlock& operator=(const Warlock &obj);
public:
	Warlock(std::string _name, std::string _title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void	setTitle(const std::string a);
	void	introduce() const;
};

#endif