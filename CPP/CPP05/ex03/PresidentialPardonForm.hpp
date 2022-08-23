#ifndef PRESIDENTIALPARDONFORM_CPP
#define PRESIDENTIALPARDONFORM_CPP

#define P_SIGN 25
#define P_EXEC 5
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm& operator= (const PresidentialPardonForm &obj);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;
};

#endif