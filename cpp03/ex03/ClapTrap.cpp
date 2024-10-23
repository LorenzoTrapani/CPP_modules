/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:11:50 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
		std::cout << "ClapTrap assignation operator called" << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	_energyPoints -= 1;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " has been killed!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to repair itself!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}

