#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	if (obj.grade > 150)
		throw (GradeTooLowException());
	else if (obj.grade < 1)
		throw (GradeTooHighException());
	*this = obj;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &obj)
{
	grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
	return (name);
}

int	Bureaucrat::getGrade()
{
	return (grade);
}

void Bureaucrat::increaseGrade()
{
	int temp = grade - 1;
	if (temp > 150)
		throw (GradeTooLowException());
	else if (temp < 1)
		throw (GradeTooHighException());
	grade--;
}

void Bureaucrat::decreaseGrade()
{
	int temp = grade + 1;
	if (temp > 150)
		throw (GradeTooLowException());
	else if (temp < 1)
		throw (GradeTooHighException());
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &val)
{
	out << val.getName() << ", bureaucrat grade " << val.getGrade() << "." << std::endl;
	return (out);
}
