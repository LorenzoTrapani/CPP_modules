/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:25:30 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/17 16:30:58 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &str)
{
	*this = str;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &str)
{
	value = str.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::Fixed(const int value)
{
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	this->value = (int)roundf(value * (1 << bits));
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << bits);
}

int Fixed::toInt(void) const
{
	return value >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(Fixed const &str) const
{
	return value > str.getRawBits();
}

bool Fixed::operator<(Fixed const &str) const
{
	return value < str.getRawBits();
}

bool Fixed::operator>=(Fixed const &str) const
{
	return value >= str.getRawBits();
}

bool Fixed::operator<=(Fixed const &str) const
{
	return value <= str.getRawBits();
}

bool Fixed::operator==(Fixed const &str) const
{
	return value == str.getRawBits();
}

bool Fixed::operator!=(Fixed const &str) const
{
	return value != str.getRawBits();
}

Fixed Fixed::operator+(Fixed const &str) const
{
	return Fixed(toFloat() + str.toFloat());
}

Fixed Fixed::operator-(Fixed const &str) const
{
	return Fixed(toFloat() - str.toFloat());
}

Fixed Fixed::operator*(Fixed const &str) const
{
	return Fixed(toFloat() * str.toFloat());
}

Fixed Fixed::operator/(Fixed const &str) const
{
	return Fixed(toFloat() / str.toFloat());
}

Fixed &Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}


