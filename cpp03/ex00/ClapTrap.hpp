/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:37:18 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/17 16:46:49 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
	std::string name;
	int hitPoints = 10;
	int energyPoints = 10;
	int attackDamage = 0;

	public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &clapTrap);
	ClapTrap &operator=(ClapTrap const &clapTrap);
	~ClapTrap();
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif