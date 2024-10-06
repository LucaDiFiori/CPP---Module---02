/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-05 17:00:38 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-05 17:00:38 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value)
{
	this->_value = value << Fixed::_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = static_cast<int>(round(value * (1 << _bits)));
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}




bool Fixed::operator > (const Fixed& src) const
{
	return (this->_value > src.getRawBits());
}

bool Fixed::operator < (const Fixed& src) const
{
	return (this->_value < src.getRawBits());
}

bool Fixed::operator >= (const Fixed& src) const
{
	return (this->_value >= src.getRawBits());
}

bool Fixed::operator <= (const Fixed& src) const
{
	return (this->_value <= src.getRawBits());
}

bool Fixed::operator == (const Fixed& src) const
{
	return (this->_value == src.getRawBits());
}

bool Fixed::operator != (const Fixed& src) const
{
	return (this->_value != src.getRawBits());
}




Fixed Fixed::operator+(Fixed const& src) const
{
	Fixed result;
	result.setRawBits(this->_value + src.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const& src) const
{
	Fixed result;
	result.setRawBits(this->_value - src.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const& src) const
{
	Fixed result;
	result.setRawBits((this->_value * src.getRawBits()) >> Fixed::_bits);
	return (result);
}

Fixed Fixed::operator/(Fixed const& src) const
{
	Fixed result;
	result.setRawBits((this->_value << Fixed::_bits) / src.getRawBits());
	return (result);
}




Fixed& Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}




Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return(a < b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return (a > b ? a : b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	return (a < b ? a : b);
}