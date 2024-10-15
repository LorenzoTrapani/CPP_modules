/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:28:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 17:03:38 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int hordeSize = 5;
	Zombie *zombies = zombieHorde(hordeSize, "Pier");
	for (int i = 0; i < hordeSize; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}