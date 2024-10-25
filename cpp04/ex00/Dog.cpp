#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &op)
{
	if (this != &op) {
		this->type = op.type;
		std::cout << "Dog assignation operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!!!" << std::endl;
}

