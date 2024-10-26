#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &copy);
	virtual ~Cure();
	Cure &operator=(const Cure &src);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif