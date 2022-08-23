#ifndef INTERN_HPP
#define INTERN_HPP 

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern;

typedef struct s_formType
{
	std::string	name;
	Form*		(Intern::*func)(std::string target);
}	t_formType;

class Intern
{
private:
	t_formType lst[3];
	Form	*createRobotomy(std::string name);
	Form	*createPresidential(std::string name);
	Form	*createShrubbery(std::string name);
public:
	Intern();
	~Intern();
	Intern(const Intern &obj);
	Intern& operator=(const Intern &obj);

	Form	*makeForm(std::string _formName, std::string _target);
};

#endif