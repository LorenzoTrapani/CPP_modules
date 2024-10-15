/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:39:28 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/03 18:05:23 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : contactsCount(0), contactIndex(0) {}
Phonebook::~Phonebook() {};

void Phonebook::addContact(Contact &contact)
{
	if (!contact.isEmpty())
	{
		if (this->contactsCount < 8)
		{
			this->contacts[this->contactsCount] = contact;
			this->contactsCount++;
		}
		else
		{
			this->contacts[this->contactIndex] = contact;
			this->contactIndex = (this->contactIndex + 1) % 8;
		}
	}
}

void Phonebook::displayContacts()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->contactsCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncated (this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncated (this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncated (this->contacts[i].getNickname()) << std::endl;
	}
}

void Phonebook::displayContact(std::string index)
{
	int i = atoi(index.c_str()) - 1;
	if (i >= 0 && i < this->contactsCount)
	{
		std::cout << "First Name: " << this->contacts[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[i].getPhoneNumbr() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[i].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}

std::string Phonebook::truncated(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return str;
}