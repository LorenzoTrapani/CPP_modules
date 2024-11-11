#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <math.h>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	std::string const _target;

	public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

#endif