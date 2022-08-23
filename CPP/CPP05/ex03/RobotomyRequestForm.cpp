#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, R_SIGN, R_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form(obj) {}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &obj)
{
	Form::operator=(obj);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	isExecutable(executor);
	std::cout << "brrrrrrr..... brrrrrrr....." << std::endl;
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << getName() << "'s robotomizing failed." << std::endl;
}
