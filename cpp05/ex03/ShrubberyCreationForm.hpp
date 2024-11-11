#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string const _target;

	public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};

#endif