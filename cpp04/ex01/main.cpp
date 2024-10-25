/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:14:41 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/25 18:53:48 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	return 0;
}

/* int main() {
    Animal* animals[10];

    for (int i = 0; i < 5; ++i) 
		animals[i] = new Dog();
    for (int i = 5; i < 10; ++i) 
		animals[i] = new Cat();

    for (int i = 0; i < 10; ++i) 
		delete animals[i];
    return 0;
} */