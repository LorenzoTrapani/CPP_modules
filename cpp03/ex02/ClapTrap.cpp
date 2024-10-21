/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/21 18:20:14 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "ClapTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy or dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount > this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " has been killed!" << std::endl;
	this->_hitPoints -= amount;
	this->_energyPoints -= 1;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy or dead!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
}

