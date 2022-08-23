#include "Intern.hpp"

Intern::Intern()
{
	lst[0].name = "robotomy request";
	lst[0].func = &Intern::createRobotomy;

	lst[1].name = "presidential pardon";
	lst[1].func = &Intern::createPresidential;

	lst[2].name = "shrubbery creation";
	lst[2].func = &Intern::createShrubbery;
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

Form*	Intern::createRobotomy(std::string name)
{
	return (new RobotomyRequestForm(name));
}

Form*	Intern::createPresidential(std::string name)
{
	return (new PresidentialPardonForm(name));
}

Form*	Intern::createShrubbery(std::string name)
{
	return (new ShrubberyCreationForm(name));
}

Form*	Intern::makeForm(std::string _formName, std::string _target)
{
	for (int i = 0; i < 3; i++)
	{
		if (!lst[i].name.compare(_formName))
		{
			std::cout << "Intern creates " << lst[i].name << "." << std::endl;
			return ((this->*lst[i].func)(_target));
		}
	}
	std::cout << "Error : Invalid type." << std::endl;
	return (NULL);
}
