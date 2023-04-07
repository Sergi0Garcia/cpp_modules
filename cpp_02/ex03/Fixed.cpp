/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:48:18 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 16:48:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNumber = 0;
	return ;
}

Fixed::Fixed(const int num) : _fixedPointNumber(num << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float num) : _fixedPointNumber(std::roundf( num * ( 1 << _fractionalBits))) 
{
    // std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointNumber > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointNumber < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointNumber >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointNumber <= other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointNumber != other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointNumber == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const 
{
	float sum = this->toFloat() + other.toFloat();
	return (Fixed(sum));
}

Fixed Fixed::operator-(const Fixed &other) const 
{
	float sub = this->toFloat() - other.toFloat();
	return (Fixed(sub));
}

Fixed Fixed::operator*(const Fixed &other) const 
{
	float mult = this->toFloat() * other.toFloat();
	return (Fixed(mult));
}

Fixed Fixed::operator/(const Fixed &other) const 
{
	float div = this->toFloat() / other.toFloat();
	return (Fixed(div));
}

Fixed& Fixed::operator++(void) 
{
    ++this->_fixedPointNumber;
    return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed copy(*this);
	this->_fixedPointNumber++;
	return (copy);
}

Fixed& Fixed::operator--(void) 
{
    --this->_fixedPointNumber;
    return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed copy(*this);
	this->_fixedPointNumber--;
	return (copy);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	// std::cout << "min ..." << std::endl;
	if (num1 < num2)
		return (num1);
	return (num2);	
}

const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
	// std::cout << "const min ..." << std::endl;
	if (num1 < num2)
		return (num1);
	return (num2);	
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	// std::cout << "max ..." << std::endl;
	if (num1 > num2)
		return (num1);
	return (num2);	
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
	// std::cout << "const max ..." << std::endl;
	if (num1 > num2)
		return (num1);
	return (num2);	
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num) 
{
	// std::cout << "stream operator overload" << std::endl;
    stream << num.toFloat();
    return (stream);
}