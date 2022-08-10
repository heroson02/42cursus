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
	grade--;
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
}

void Bureaucrat::decreaseGrade()
{
	grade++;
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
}

void Bureaucrat::signForm(Form &input)
{
	if (input.getSign() == true)
		std::cout	<< name << " couldn't sign " << input.getName()
						<< " because already signed." << std::endl;
	else if (input.getSign() == false)
	{
		try
		{
			input.beSigned(*this);
			std::cout << name << " signed " << input.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout	<< name << " couldn't sign " << input.getName()
						<< " because " << e.what() << std::endl;
		}	
	}
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
