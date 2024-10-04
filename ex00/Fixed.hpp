/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 11:44:16 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-02 11:44:16 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed(); // default constructor
		Fixed(const Fixed &src); // copy constructor
		Fixed& operator=(const Fixed& src); // Copy assignment operator
		~Fixed(); // Destructor

		// Getters and Setters
		int getRawBits(void) const;
		
		/* Note: The const keyword specifies that the value of raw cannot be 
		* modified within the setRawBits function. In other words, 
		* once raw is passed to the function, its value is read-only inside that function*/
		void setRawBits(int const raw); 
};

#endif