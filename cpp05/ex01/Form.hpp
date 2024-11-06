#ifndef FORM_H
#define FORM_H

class Form;

#include "Bureaucrat.hpp"

class Form
{
	private:
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _executeGrade;

	public:
	Form(std::string const &name, int signGrade, int executeGrade);
	~Form();

	std::string const &getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
