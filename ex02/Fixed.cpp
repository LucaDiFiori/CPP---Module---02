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
}

// Constructor with int
/* convert the integer 'value' to its fixed-point representation by multiplying 
*  it by 2^fractional_bits (shift 8 bits to the lesf)
*
*  Note: i use Fixed::_bits instead of _bits because _bits is a static member 
*        of the class Fixed
*/
Fixed::Fixed(const int value)
{
	this->_value = value << Fixed::_bits;
}

// Constructor with float
Fixed::Fixed(const float value)
{
	this->_value = static_cast<int>(round(value * (1 << _bits)));
}

// Copy constructor
Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
}

// Getters and Setters
int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

// member functions
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

// Overload operator << to print Fixed as float
std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}



// Overload comparison operators: >, <, >=, <=, == and !=
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



// Overload arithmetic operators: +, -, *, and /
Fixed Fixed::operator+(Fixed const& src) const
{
	Fixed result; // create a new Fixed object
	result.setRawBits(this->_value + src.getRawBits()); // set the value of the new object
	return (result); // return the new object
}

Fixed Fixed::operator-(Fixed const& src) const
{
	Fixed result;
	result.setRawBits(this->_value - src.getRawBits());
	return (result);
}

/* Multiply the raw values and then shift right by the number of fractional bits:
*
* this->_value * src.getRawBits(): This part multiplies the raw value of the current object 
								   (this->_value) by the raw value of the src object. 
								   Here, _value holds the fixed-point representation 
								   of the number.
*
* >> _bits: After multiplying, we need to adjust the result to account for the 
            fixed-point representation. Because both operands are fixed-point 
			numbers, the multiplication results in a larger value that includes 
			both the integer and fractional parts.

			Since each fixed-point number has 8 bits reserved for the fractional 
			part (as defined by _bits), you need to shift the result right by 
			_bits to get the correct fixed-point representation. 
			This effectively divides the product by 2^8  converting the result 
			back to a fixed-point number.
*/
Fixed Fixed::operator*(Fixed const& src) const
{
	Fixed result;
	result.setRawBits((this->_value * src.getRawBits()) >> Fixed::_bits);
	return (result);
}

/* Divide the raw values and then shift left by the number of fractional bits:
* 
* this->_value << Fixed::_bits_bits: 
  The current object's raw value is shifted left by _bits. 
  This operation effectively multiplies the current value by 2^8,
  adjusting for fixed-point representation
*/
Fixed Fixed::operator/(Fixed const& src) const
{
	Fixed result;
	result.setRawBits((this->_value << Fixed::_bits) / src.getRawBits());
	return (result);
}



// Overload pre increment-decrement 1 + ϵ > 1,1 - ϵ < 1
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

// Overload post increment-decrement
Fixed Fixed::operator++(int)
{
	// create a temporary object, with the copy constructor, that will store the current object
	Fixed tmp(*this);
	// increment the current object
	operator++();
	// return the temporary object
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}



// Overload max and min functions
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	// if a is greater than b, return a, else return b
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