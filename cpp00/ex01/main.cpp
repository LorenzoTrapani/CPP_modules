/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:39:50 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/03 17:55:40 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	Contact newContact;
	std::string input;

	std::cout << "Welcome to the phonebook!" << std::endl;
	std::cout << "Enter a command: ADD, SEARCH or EXIT." << std::endl;

	while (1) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			std::cout << "Enter the first name: ";
			std::getline(std::cin, input);
			newContact.setFirstName(input);

			std::cout << "Enter the last name: ";
			std::getline(std::cin, input);
			newContact.setLastName(input);

			std::cout << "Enter the nickname: ";
			std::getline(std::cin, input);
			newContact.setNickname(input);

			std::cout << "Enter the phone number: ";
			std::getline(std::cin, input);
			newContact.setPhoneNumbr(input);

			std::cout << "Enter the darkest secret: ";
			std::getline(std::cin, input);
			newContact.setDarkestSecret(input);

			if (!newContact.isEmpty()) {
				phonebook.addContact(newContact);
				std::cout << "Contact added!" << std::endl;
			}
			else {
				std::cout << "Contact not added. One or more fields are empty." << std::endl;
			}
		}
		else if (input == "SEARCH") {
			phonebook.displayContacts();
			std::cout << "Enter the index of the contact you want to see: ";
			std::getline(std::cin, input);
			phonebook.displayContact(input);
		}
		else if (input == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid command. Enter ADD, SEARCH or EXIT." << std::endl;
		}
	}
	return 0;
}