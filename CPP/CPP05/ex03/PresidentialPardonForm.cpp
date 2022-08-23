#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form(target, P_SIGN, P_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: Form(obj) {}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &obj)
{
	Form::operator=(obj);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	isExecutable(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
