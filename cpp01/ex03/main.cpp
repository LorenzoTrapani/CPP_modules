/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 17:38:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon classic = Weapon("spear");
	Weapon weird = Weapon("Baby head");

	HumanA bob("Bob", classic);
	HumanB steve("Steve");

	bob.attack();
	classic.setType("axe");
	bob.attack();

	steve.setWeapon(weird);
	steve.attack();
	weird.setType("Dead puppy");
	steve.setWeapon(weird);
	steve.attack();
	
	return 0;
}