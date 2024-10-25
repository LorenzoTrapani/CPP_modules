/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:34:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:57:36 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap;
	ScavTrap scavTrap2("ScavTrap2");
	ScavTrap scavTrap3(scavTrap2);

	scavTrap.attack("target");
	scavTrap2.attack("target");
	scavTrap3.attack("target");

	scavTrap.guardGate();
	
	scavTrap2.takeDamage(10);
	scavTrap2.beRepaired(5);
	scavTrap3.takeDamage(100);
	return 0;
}