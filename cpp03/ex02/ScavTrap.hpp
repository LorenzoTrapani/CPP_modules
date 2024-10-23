/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:00:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/23 17:10:54 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap ();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &src);
	~ScavTrap();
	void attack(std::string const &target);
	void guardGate();
};

#endif