/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 09:17:04 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-04 09:17:04 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    // create three points to form a triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test: point inside the triangle
    Point inside(5.0f, 5.0f);
    if (bsp(a, b, c, inside))
        std::cout << "The point (5.0, 5.0) is inside the triangle." << std::endl;
    else
        std::cout << "The point (5.0, 5.0) is outside the triangle." << std::endl;

    // Test: point on the vertex of the triangle
    Point onVertex(0.0f, 0.0f);
    if (bsp(a, b, c, onVertex))
        std::cout << "The point (0.0, 0.0) is inside the triangle." << std::endl;
    else
        std::cout << "The point (0.0, 0.0) is outside the triangle." << std::endl;

    // Test: point outside the triangle
    Point outside(15.0f, 5.0f);
    if (bsp(a, b, c, outside))
        std::cout << "The point (15.0, 5.0) is inside the triangle." << std::endl;
    else
        std::cout << "The point (15.0, 5.0) is outside the triangle." << std::endl;

    return (0);
}
