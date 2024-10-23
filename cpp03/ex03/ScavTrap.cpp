/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:59:51 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:50:33 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) 
{
	if (this != &src) {
		ClapTrap::operator=(src);
		std::cout << "ScavTrap assignation operator called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }

    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered Gatekeeper mode!" << std::endl;
}
