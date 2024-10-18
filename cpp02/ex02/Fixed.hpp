/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:25:39 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/17 16:29:04 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
	Fixed(const int value);
	Fixed(const float value);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	bool operator>(Fixed const &str) const;
	bool operator<(Fixed const &str) const;
	bool operator>=(Fixed const &str) const;
	bool operator<=(Fixed const &str) const;
	bool operator==(Fixed const &str) const;
	bool operator!=(Fixed const &str) const;
	Fixed operator+(Fixed const &str) const;
	Fixed operator-(Fixed const &str) const;
	Fixed operator*(Fixed const &str) const;
	Fixed operator/(Fixed const &str) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif