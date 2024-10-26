#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "Elephant";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		std::cout << "Animal assignation operator called" << std::endl;
	}
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "Trumpeting elephants.." << std::endl;
}