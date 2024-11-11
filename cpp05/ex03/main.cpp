#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/* int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
} */

int main()
{
	Intern someRandomIntern;
	Bureaucrat john("John the bureaucrat", 1);
	AForm *form;

	std::cout << "\n//Shrubbery//" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "Home");
	john.signForm(*form);
	john.executeForm(*form);
	delete form;

	std::cout <<"\n//Robotomy//" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	john.signForm(*form);
	john.executeForm(*form);
	delete form;

	std::cout << "\n//Presidential Pardon//" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Trump");
	john.signForm(*form);
	john.executeForm(*form);
	delete form;

	std::cout << "\n//Nonexistent form//" << std::endl;
	form = someRandomIntern.makeForm("Galaxy destroyer", "target");
}
