/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:01:42 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/21 18:14:23 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap clap("ClapTrap");
	FragTrap frag("FragTrap");

	clap.attack("FragTrap");
	frag.takeDamage(30);
	frag.beRepaired(10);
	frag.takeDamage(101);
	frag.attack("ClapTrap");
	clap.takeDamage(30);
	clap.beRepaired(10);
	frag.highFivesGuys();
	clap.highFivesGuys();
	return 0;
}