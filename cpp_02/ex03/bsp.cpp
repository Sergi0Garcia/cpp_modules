/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:25:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 17:46:17 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float area;
    area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 *(y1 - y2)) / 2.0;
    if (area < 0)
        area *= -1;
    return (area);
} 

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   float A = area (x1, y1, x2, y2, x3, y3);
   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x3, y3); 
   float A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // std::cout << "a: " << a.getX() << " " << a.getY() << std::endl;
    // std::cout << "b: " << b.getX() << " " << b.getY() << std::endl;
    // std::cout << "c: " << c.getX() << " " << c.getY() << std::endl;
    if (isInside(a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt(), point.getX().toInt(), point.getY().toInt()))
        return (true);
    return (false);
}
