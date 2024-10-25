#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Elephant";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
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
		this->type = src.type;
		std::cout << "Animal assignation operator called" << std::endl;
	}
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Trumpeting elephants.." << std::endl;
}