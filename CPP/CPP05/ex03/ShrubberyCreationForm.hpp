#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#define S_SIGN 145
#define S_EXEC 137
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm &obj);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;
};

#endif