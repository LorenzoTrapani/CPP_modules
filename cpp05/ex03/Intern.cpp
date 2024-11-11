#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	if (formName.empty())
	{
		std::cout << "Form name cannot be empty" << std::endl;
		return (NULL);
	}
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*formCreators[3])(std::string) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	std::cout << "Error: Form name '" + formName + "' does not exist." << std::endl;
	return (NULL);
}

