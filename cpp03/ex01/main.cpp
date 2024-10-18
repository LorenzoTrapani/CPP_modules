/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:34:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/18 16:57:08 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Pier");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3 = clapTrap;

	clapTrap.attack("target");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	clapTrap2.attack("target2");
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(2);

	clapTrap3.attack("target3");
	clapTrap3.takeDamage(2);
	clapTrap3.beRepaired(1);
	return 0;
}