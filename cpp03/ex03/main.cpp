/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:59:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:48:38 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
    std::cout << "---- Creazione di DiamondTrap ----" << std::endl;
    DiamondTrap diamond("David");

    std::cout << "\n---- Chiamata a whoAmI ----" << std::endl;
    diamond.whoAmI();

    std::cout << "\n---- Attacco di DiamondTrap con funzione ereditata da ScavTrap ----" << std::endl;
    diamond.attack("target1");

    std::cout << "\n---- Riparazione di DiamondTrap ----" << std::endl;
    diamond.beRepaired(20);

    std::cout << "\n---- DiamondTrap subisce danno ----" << std::endl;
    diamond.takeDamage(30);

    std::cout << "\n---- Modalità guardGate di DiamondTrap ----" << std::endl;
    diamond.guardGate();

    std::cout << "\n---- High Five richiesto da DiamondTrap ----" << std::endl;
    diamond.highFivesGuys();

    std::cout << "\n---- DiamondTrap subisce danno fino alla morte ----" << std::endl;
    diamond.takeDamage(100);

    std::cout << "\n---- Tentativo di attacco e riparazione dopo la morte ----" << std::endl;
    diamond.attack("target2");
    diamond.beRepaired(50);

    std::cout << "\n---- Distruzione di DiamondTrap ----" << std::endl;
    return 0;
}
