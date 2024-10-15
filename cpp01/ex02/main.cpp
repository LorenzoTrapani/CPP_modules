/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:10:43 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/15 17:08:50 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Memory adress of the string: " << &str << std::endl;
	std::cout << "Memory adress of the pointer: " << ptr << std::endl;
	std::cout << "Memory adress of the reference: " << &ref << std::endl;

	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value of the pointer: " << *ptr << std::endl;
	std::cout << "Value of the reference: " << ref << std::endl;

	return 0;
}