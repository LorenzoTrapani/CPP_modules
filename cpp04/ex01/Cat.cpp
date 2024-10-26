#include "Cat.hpp"

Cat::Cat() : Animal()
{
	brain = new Brain();
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	this->_type = copy._type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) 
{
	if (this != &src) {
		Animal::operator=(src);
		this->_type = src._type;
		delete brain;
		brain = new Brain(*src.brain);
		std::cout << "Cat assignation operator called" << std::endl;
	}
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat don't bark." << std::endl;
}

