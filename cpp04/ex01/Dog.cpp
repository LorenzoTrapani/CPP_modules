#include "Dog.hpp"

Dog::Dog() : Animal()
{
	brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	this->type = copy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src) {
		Animal::operator=(src);
		this->type = src.type;
		delete brain;
		brain = new Brain(*src.brain);
		std::cout << "Dog assignation operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!!!" << std::endl;
}

