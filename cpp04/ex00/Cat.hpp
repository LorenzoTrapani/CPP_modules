#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &copy);
    virtual ~Cat();
    Cat &operator=(const Cat &op);

    virtual void makeSound() const;
};

#endif