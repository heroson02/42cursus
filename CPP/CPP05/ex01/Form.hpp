#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSign;
	const int			signGrade;
	const int			execGrade;
	Form(void);
public:
	Form(std::string _name, int _signGrade, int _execGrade);
	Form(const Form &obj);
	Form& operator= (const Form &obj);
	~Form();

	std::string getName() const;
	bool	getSign();
	int	getSignGrade() const;
	int	getExecGrade() const;
	void	beSigned(Bureaucrat &obj);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form &val);

#endif