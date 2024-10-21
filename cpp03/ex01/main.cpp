/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:34:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/19 15:25:29 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	/* ScavTrap scavTrap("ScavTrap");
	ScavTrap scavTrap2("ScavTrap2");
	ScavTrap scavTrap3("scavTrap3"); */

	ScavTrap scavTrap;
	ScavTrap scavTrap2("ScavTrap2");
	ScavTrap scavTrap3(scavTrap2);

	scavTrap.attack("target");
	scavTrap2.attack("target");
	scavTrap3.attack("target");
	scavTrap.guardGate();
	return 0;
}