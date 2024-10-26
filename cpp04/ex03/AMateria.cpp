#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}