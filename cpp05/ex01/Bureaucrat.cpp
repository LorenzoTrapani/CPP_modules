#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " has a grade of " << bureaucrat.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSign() == true)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because the form is already signed" << std::endl;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << _name << " signs " << form.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
}
