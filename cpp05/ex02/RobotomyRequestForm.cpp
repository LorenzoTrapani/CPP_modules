#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "*drilling noises* ";
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}