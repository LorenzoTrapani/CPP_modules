#include "AForm.hpp"


AForm::AForm(std::string const &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

std::string const &AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
	out << Aform.getName() << " Aform:\nSign grade = " << Aform.getSignGrade() << "\nExecute grade = " << Aform.getExecuteGrade() << "\nSigned = " << ( Aform.getSign() ? "true" : "false");
	return out;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

const char *AForm::FormNotExecutedException::what() const throw() {
	return "form is not executed";
}
