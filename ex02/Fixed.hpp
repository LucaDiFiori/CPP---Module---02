/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 09:16:51 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-04 09:16:51 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);

		Fixed& operator = (const Fixed& src);
		~Fixed();

		// Getters and Setters
		int getRawBits(void) const;
		void setRawBits(const int raw); 

		// member functions
		float toFloat(void) const;
		int toInt(void) const;

		// Overload comparison operators: >, <, >=, <=, == and !=.
		bool operator > (const Fixed& src) const;
		bool operator < (const Fixed& src) const;
		bool operator >= (const Fixed& src) const;
		bool operator <= (const Fixed& src) const;
		bool operator == (const Fixed& src) const;
		bool operator != (const Fixed& src) const;

		// Overload arithmetic operators: +, -, *, and /
		Fixed operator + (const Fixed& src) const;
		Fixed operator - (const Fixed& src) const;
		Fixed operator * (const Fixed& src) const;
		Fixed operator / (const Fixed& src) const;

		/* Overload pre increment-decrement 1 + ϵ > 1,1 - ϵ < 1
		* ------------------------------------------------------
		*
		* Pre-increment (++obj): Has no parameter.
		*
		* The pre-decrement operator decrements the value and returns the object 
		* itself (that’s why it returns a reference to the object).
		*/
		Fixed& operator++();
		Fixed& operator--();

		/*Overload post increment-decrement
		*----------------------------------
		*
		* The int parameter in the post-increment and post-decrement operators 
		* is a way for the compiler to differentiate between pre-increment and 
		* post-increment (or pre-decrement and post-decrement) operators.
		*
		* Post-increment (obj++): Takes a single int parameter, but this parameter 
		* is not used inside the function. It’s just a way for the compiler to 
		* distinguish between pre- and post-increment. 
		* The value of this int is ignored.
		*/
		Fixed operator++(int);
		Fixed operator--(int);

		/* Overload functions
		*
		* The const version is necessary when you are dealing with constant objects. 
		* If you tried to pass const objects to the non-const version, the compiler 
		* would give an error because you can't bind a const reference to a 
		* non-const reference.

		* Note:
		* The non-const version allows you to return a reference to the object, 
		* which can be modified.
		*/
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Overload operator << to print Fixed
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif