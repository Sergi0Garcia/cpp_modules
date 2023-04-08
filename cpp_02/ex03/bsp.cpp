/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:25:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/08 13:29:34 by segarcia         ###   ########.fr       */
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

bool isVertexPoint(int x1, int y1, int x, int y)
{
    if (x1 == x && y1 == y)
        return (true);
    return (false);
}

bool pointOnLine(int x1, int y1, int x2, int y2, int px, int py) 
{
    float m = (float)(y2 - y1) / (float)(x2 - x1);
    float y = m * (px - x1) + y1;
    if (y == py)
        return (true);
    return (false);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   if (isVertexPoint(x1, y1, x, y) ||
       isVertexPoint(x2, y2, x, y) ||
       isVertexPoint(x3, y3, x, y)){
            std::cout << "Point is a vertex" << std::endl;
            return (false);
        }
  if (pointOnLine(x1, y1, x2, y2, x, y) ||
      pointOnLine(x1, y1, x3, y3, x, y) ||
      pointOnLine(x2, y2, x3, y3, x, y)){
            std::cout << "Point is in line" << std::endl;
            return (false);
    }
   float areaABC = area(x1, y1, x2, y2, x3, y3);
   float areaPBC = area (x, y, x2, y2, x3, y3);
   float areaPAC = area (x1, y1, x, y, x3, y3);
   float areaPAB = area (x1, y1, x2, y2, x, y);
   return (areaABC == areaPBC + areaPAC + areaPAB);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (isInside(a.getX().toInt(), a.getY().toInt(), 
                 b.getX().toInt(), b.getY().toInt(),
                 c.getX().toInt(), c.getY().toInt(), 
                 point.getX().toInt(), point.getY().toInt()))
        return (true);
    return (false);
}
