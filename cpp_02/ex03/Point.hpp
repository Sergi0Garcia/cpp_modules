/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:16 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/08 13:29:36 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point &other);
    Point& operator=(const Point &other);
    ~Point(void);
    
    Fixed getX(void) const;
    Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif