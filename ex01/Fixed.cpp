/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 09:16:58 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-04 09:16:58 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with int
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	/* convert the integer 'value' to its fixed-point representation by multiplying 
	   it by 2^fractional_bits (shift 8 bits to the lesf)*/
	this->_value = value << Fixed::_bits;
}












// Copy constructor
Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
