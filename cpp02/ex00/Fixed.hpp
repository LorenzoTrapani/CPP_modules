/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:58:04 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/17 15:33:46 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int value;
	static const int bits = 8;

	public:
	Fixed();
	Fixed(const Fixed &str);
	~Fixed();
	Fixed &operator=(const Fixed &str);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif