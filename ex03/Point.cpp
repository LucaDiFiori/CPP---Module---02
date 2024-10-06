/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-05 17:11:45 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-05 17:11:45 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Parameterized constructor
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point& src) : _x(src._x), _y(src._y) {}

// Assignment operator
// Since x and y are const, we cannot assign them new values after initialization
// Therefore, there's nothing to assign in this case
Point& Point::operator=(const Point& src)
{
	(void)src;
	std::cout << "Assignment operation is not allowed for const members" << std::endl;
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}