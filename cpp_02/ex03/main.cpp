/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/08 13:29:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Colors.hpp"
#include "Point.hpp"

// Example
// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

int main(void) 
{
    // Triangle vertices
    Point const a(0.0, 0.0);
    Point const b(10.0, 30.0);
    Point const c(20.0, 0.0);
    // Points
    Point const pInside(10.0, 15.0);
    Point const pOutside(30.0, 50.0);
    Point const inVertex(20.0, 0.0);
    Point const inLine(10.0, 0);

    if (bsp(a, b, c, pInside)) {
        std::cout << "Point is inside" << std::endl;
    } else {
        std::cout << "Point is outside" << std::endl;
    }
    return (0);
}