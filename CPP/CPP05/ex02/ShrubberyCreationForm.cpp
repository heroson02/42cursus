#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, S_SIGN, S_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form(obj) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj)
{
	Form::operator=(obj);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream output;

	isExecutable(executor);
	output.open(getName() + "_shrubbery");
	std::string tree =	"	     ccee88oo		\n"
						"  C8O8O8Q8PoOb o8oo	\n"
						" dOB69QO8PdUOpugoO9bD	\n"
						"CgggbU8OU qOp qOdoUOdcb\n"
						"    6OuU  /p u gcoUodpP\n"
						"      \\\"//  /douUP	\n"
						"        \\\"////		\n"
						"         |||/\"			\n"
						"         |||\"/			\n"
						"         |||||			\n"
						"   .....//||||\"....	";
	output << tree;	
}
