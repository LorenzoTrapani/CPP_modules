#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    ShrubberyCreationForm shrubbery("Tree");
    RobotomyRequestForm robotomy("Alice");
    PresidentialPardonForm pardon("Charlie");

    try {
    	Bureaucrat bob("Bob", 1);
		Bureaucrat alice("Alice", 142);
		Bureaucrat charlie("Charlie", 25);

        std::cout << "=== ShrubberyCreationForm Test ===" << std::endl;
        bob.signForm(shrubbery);
		alice.executeForm(shrubbery);
        bob.executeForm(shrubbery);

        std::cout << "\n=== RobotomyRequestForm Test ===" << std::endl;
        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        std::cout << "\n=== PresidentialPardonForm Test ===" << std::endl;
        bob.signForm(pardon);
        bob.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 140);

        std::cout << "\n=== Lower Grade Bureaucrat Test (ShrubberyCreationForm) ===" << std::endl;
        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        std::cout << "\n=== Lower Grade Bureaucrat Test (RobotomyRequestForm) ===" << std::endl;
        john.signForm(robotomy);
        john.executeForm(robotomy);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
