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

		// Overload pre increment-decrement 1 + ϵ > 1,1 - ϵ < 1
		Fixed& operator++();
		Fixed& operator--();

		//Overload post increment-decrement
		Fixed operator++(int);
		Fixed operator--(int);

		// Overload functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif