#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#define R_SIGN 75
#define R_EXEC 45
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm& operator= (const RobotomyRequestForm &obj);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;
};

#endif