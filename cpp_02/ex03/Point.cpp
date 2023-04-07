/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:21:40 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 17:45:30 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
    return ;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
    return ;
}

Point::Point(const Point &other): _x(other._x), _y(other._y)
{
    return ;
}

Point& Point::operator=(const Point &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

Point::~Point(void)
{
    return ;
}

Fixed Point::getX(void) const
{
    return (this->_x);
}

Fixed Point::getY(void) const
{
    return (this->_y);
}