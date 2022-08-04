#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("NULL"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::cout << "Bureaucrat argument constructor called" << std::endl;
	try
	{
		if (grade > 150)
			throw(GradeTooLowException());
		else if (grade < 1)
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		exit(1);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &obj)
{
	*this = obj;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

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
	try
	{
		grade--;
		if (grade > 150)
			throw(GradeTooLowException());
		else if (grade < 1)
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		exit(1);
	}
}

void Bureaucrat::decreaseGrade()
{
	try
	{
		grade++;
		if (grade > 150)
			throw(GradeTooLowException());
		else if (grade < 1)
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		exit(1);
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
