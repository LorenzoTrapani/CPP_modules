#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <vector>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *inventory[4];
	std::vector<AMateria *> _trash;

public:
	Character();
	Character(std::string name);
	Character(const Character &copy);
	virtual ~Character();
	Character &operator=(const Character &src);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void clearTrash();
};

#endif