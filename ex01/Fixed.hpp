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
		Fixed(const int value); // constructor with int
		Fixed(const float value); // constructor with float
		Fixed(const Fixed &src);

		Fixed& operator=(const Fixed& src);
		~Fixed();

		// Getters and Setters
		int getRawBits(void) const;
		void setRawBits(const int raw); 

		// member functions
		float toFloat(void) const;
		int toInt(void) const;
};

// Overload operator << to print Fixed
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif