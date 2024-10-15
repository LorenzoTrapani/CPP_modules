/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:39:47 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:56 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Unknown level: " << level << std::endl;
}

void Harl::debug()
{
	std::cout << "DEBUG: Microscope lens calibrated. Cellular sample 204 appears stable under low light. Noted slight twitch in amoeba membrane—could be contamination or an internal response." << std::endl;
}

void Harl::info()
{
	std::cout << "INFO: Sample 204 introduced to compound solution. Initial reaction minimal, though there’s an odd, faint glow developing. Might be fluorescence, but more testing needed." << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING: Sample temperature rising unexpectedly. It’s still within safe limits, but if it continues, we might need to recalibrate the incubator." << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR: Compound solution has crystallized in the sample tube! Procedure compromised, and there’s a risk of contaminating the entire set. Experiment halted." << std::endl;
}
