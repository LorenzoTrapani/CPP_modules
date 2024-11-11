#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &assign);
	AForm *makeForm(std::string formName, std::string target);

private:
	AForm *createShrubberyCreationForm(std::string target);
	AForm *createRobotomyRequestForm(std::string target);
	AForm *createPresidentialPardonForm(std::string target);
};

#endif