/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-05 17:12:01 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-05 17:12:01 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
/* bsp:
*  ----
*  To determine if a point is inside a triangle, the area method works by checking 
*  if the sum of the areas of three sub-triangles (formed by the point and each 
*  pair of triangle vertices) equals the area of the triangle itself.
*
*  1) The area of a triangle formed by three points (x1, y1), (x2, y2), and (x3, y3) 
*     can be calculated using the determinant formula:
*     Area = |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2|
*  
*  2) The bsp function takes four Point objects as arguments: a, b, c, and point,
*     calculates the area of the triangle formed by a, b, and c, and then calculates
*     the areas of the three sub-triangles formed by the point and each pair of
*     triangle vertices. If the sum of the areas of the three sub-triangles equals
*     the area of the triangle, the point is inside the triangle.
*/


/* 1) Calculate the area of the triangle formed by three points
*  ------------------------------------------------------------
*  - extract the x and y coordinates of the three points
*  - calculate the area using the determinant formula
*  - return the absolute value of the area
*/
Fixed area (Point const& a, Point const& b, Point const& c)
{
	Fixed x_1 = a.getX();
	Fixed y_1 = a.getY();
	Fixed x_2 = b.getX();
	Fixed y_2 = b.getY();
	Fixed x_3 = c.getX();
	Fixed y_3 = c.getY();

	Fixed area = (x_1 * (y_2 - y_3) + x_2 * (y_3 - y_1) + x_3 * (y_1 - y_2)) / 2;

	return (area < 0 ? area * -1 : area);
}

/* 2) Check if a point is inside a triangle
*
*  - check if the point is on any of the vertices
*  - calculate the area of the triangle formed by a, b, and c
*  - calculate the areas of the three sub-triangles formed by the point and each pair of triangle vertices
*  - return true if the sum of the areas of the three sub-triangles equals the area of the triangle
*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Check if the point is on any of the vertices
    if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY())) {
        return false; // The point is on a vertex, return false
    }

	Fixed total_area = area(a, b, c);

	Fixed sub_area_1 = area(a, b, point);
	Fixed sub_area_2 = area(b, c, point);
	Fixed sub_area_3 = area(c, a, point);

	return (total_area == sub_area_1 + sub_area_2 + sub_area_3);
}