/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:03:01 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/21 16:40:23 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie = Zombie("Alfred");
	zombie.announce();
	randomChump("Steve");
	Zombie *zombie2 = newZombie("Bob");
	zombie2->announce();
	delete zombie2;
	return 0;
}