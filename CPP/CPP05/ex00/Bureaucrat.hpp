#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat();
public:
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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &val);

#endif