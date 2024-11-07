#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string const _target;

	public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif