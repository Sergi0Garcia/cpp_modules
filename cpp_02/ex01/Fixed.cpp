/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:48:18 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 10:07:30 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNumber = 0;
	return ;
}

Fixed::Fixed(const int num) : _fixedPointNumber(num << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float num) : _fixedPointNumber(std::roundf( num * ( 1 << _fractionalBits))) 
{
    std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointNumber = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->getRawBits()) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void)const 
{
	return (this->_fixedPointNumber >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num) 
{
	// std::cout << "stream operator overload" << std::endl;
    stream << num.toFloat();
    return (stream);
}