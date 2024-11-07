#ifndef AFORM_H
#define AFORM_H

class AForm;

#include "Bureaucrat.hpp"

class AForm
{
	private:
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _executeGrade;

	public:
	AForm(std::string const &name, int signGrade, int executeGrade);
	~AForm();

	std::string const &getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception	{
		public:
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception	{
		public:
		const char *what() const throw();
	};

	class FormNotExecutedException : public std::exception	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
