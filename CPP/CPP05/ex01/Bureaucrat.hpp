#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat& operator= (const Bureaucrat &obj);
	~Bureaucrat();

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

	std::string getName();
	int	getGrade();
	void increaseGrade();
	void decreaseGrade();
	void signForm(Form &input);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &val);

#endif