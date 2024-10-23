/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:01:42 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 16:16:03 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap clap("ClapTrap");
	FragTrap frag("FragTrap");

	clap.attack("John");
	frag.takeDamage(30);
	frag.beRepaired(10);
	frag.takeDamage(101);
	clap.highFivesGuys();

	FragTrap frag2(frag);

	frag2.attack("Steve");

	frag2 = clap;

	frag2.attack("Steve");
	frag2.highFivesGuys();

	return 0;
}