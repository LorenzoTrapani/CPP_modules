/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:03:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/03 17:55:43 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
private:
	Contact contacts[8];
	int contactsCount;
	int contactIndex;
	std::string truncated(std::string str) const;

public:
	Phonebook();
	~Phonebook();
	void addContact(Contact &contact);
	void displayContacts();
	void displayContact(std::string index);
};
#endif