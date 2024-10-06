/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-05 17:11:37 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-05 17:11:37 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		Point& operator=(const Point& src);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif