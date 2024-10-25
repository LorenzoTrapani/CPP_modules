/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:18 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:58:55 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &src);
	~ClapTrap();

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif