#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
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

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src) {
		this->_type = src._type;
		std::cout << "Dog assignation operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!!!" << std::endl;
}

