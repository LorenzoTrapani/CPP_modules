#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Elephant";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &op)
{
    if (this != &op)
    {
        this->type = op.type;
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