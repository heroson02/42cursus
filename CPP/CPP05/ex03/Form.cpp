#include "Form.hpp"

Form::Form(void) : signGrade(0), execGrade(0) {}

Form::Form(std::string _name, int _signGrade, int _execGrade) : name(_name), signGrade(_signGrade), execGrade(_execGrade)
{
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	isSign = false;
}

Form::Form(const Form &obj) : name(obj.getName()), signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	isSign = obj.isSign;
}

Form& Form::operator= (const Form &obj)
{
	isSign = obj.isSign;
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (name);
}

bool	Form::getSign()
{
	return (isSign);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecGrade() const
{
	return (execGrade);
}

void	Form::beSigned(Bureaucrat &obj)
{
	int input;

	input = obj.getGrade();
	if (input > signGrade)
		throw GradeTooLowException();
	if (input <= signGrade)
		isSign = true;
}

void Form::isExecutable(const Bureaucrat &obj) const
{
	if (isSign == false)
		throw NotSigned();
	if (obj.getGrade() > execGrade)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException");
}

const char *Form::NotSigned::what(void) const throw()
{
	return ("FormNotSigned");
}

std::ostream &operator<<(std::ostream &out, Form &val)
{
	out << val.getName() << ", grade to sign " << val.getSignGrade()
		<< ", grade to execute " << val.getExecGrade() << ", sign : " << val.getSign()
		<< std::endl;
	return (out);
}
