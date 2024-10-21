/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/21 18:07:09 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with name" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	std::cout << "FragTrap assignation operator" << std::endl;
	ClapTrap::operator=(fragTrap);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " says: High five guys!" << std::endl;
}
