#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

std::string const &Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << " form:\nSign grade = " << form.getSignGrade() << "\nExecute grade = " << form.getExecuteGrade() << "\nSigned = " << ( form.getSign() ? "true" : "false");
	return out;
}

