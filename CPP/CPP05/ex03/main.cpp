# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	Intern son;
	Bureaucrat a("YY", 40);
	Bureaucrat b("ZZ", 3);

	Form *first = son.makeForm("what", "firstForm");
	Form *second = son.makeForm("robotomy request", "secondForm");
	Form *third = son.makeForm("presidential pardon", "thirdForm");
	std::cout << std::endl;

	(void)first;
	std::cout << "target form : " << second->getName() << std::endl;
	a.signForm(*second);
	a.executeForm(*second);
	std::cout << std::endl;

	std::cout << "target form : " << third->getName() << std::endl;
	b.signForm(*third);
	b.executeForm(*third);
}
