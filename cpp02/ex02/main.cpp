/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:25:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/22 15:24:20 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Initial value: " << a << std::endl;
	std::cout << "Pre-increment: " << ++a << std::endl;
	std::cout << "Final value: " << a << std::endl;
	std::cout << "Post-increment: " << a++ << std::endl;
	std::cout << "Final value: " << a << std::endl;


	std::cout << "b: " << b << std::endl;
	std::cout << "Max: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min: " << Fixed::min(a, b) << std::endl;

	a = Fixed(10);
	const Fixed c(5);

	std::cout << "a: " << a << " c: " << c << std::endl;
	std::cout << "a + c: " << a + c << std::endl;
	std::cout << "a - c: " << a - c << std::endl;
	std::cout << "a * c: " << a * c << std::endl;
	std::cout << "a / c: " << a / c << std::endl;

	if (a > c)
		std::cout << "a is greater than c" << std::endl;
	if (c < a)
		std::cout << "c is less than a" << std::endl;
	if (a >= c)
		std::cout << "a is greater or equal to c" << std::endl;
	if (c <= a)
		std::cout << "c is less or equal to a" << std::endl;
	if (a != c)
		std::cout << "a is different from c" << std::endl;
	a = Fixed(5);
	std::cout << "Value of a is set to " << a << std::endl;
	if (a == c)
		std::cout << "a is equal to c" << std::endl;
	return 0;
}