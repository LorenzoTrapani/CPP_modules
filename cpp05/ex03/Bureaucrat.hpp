#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

#include "AForm.hpp"

class Bureaucrat
{
	private:
	std::string const _name;
	int _grade;

	public:
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();

	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);

	void executeForm(AForm const &form) const;

	class GradeTooHighException : public std::exception	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif

