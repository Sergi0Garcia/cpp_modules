/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:39:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 16:38:32 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * the copy constructor creates a new object by copying the values of other into the newly created object. 
 * The copy assignment operator overload, on the other hand, copies the values of other into the existing object pointed to by this. 
*/
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {
private:
	int					_fixedPointNumber;
	static const int	_fractionalBits = 8; 
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other); 					// copy constructor
	Fixed& operator=(const Fixed& other); 		// copy assignment operator overload
	~Fixed(void);
	
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int   	toInt(void) const;

	bool    operator>(const Fixed &other) const;
	bool    operator<(const Fixed &other) const;
	bool    operator>=(const Fixed &other) const;
	bool    operator<=(const Fixed &other) const;
	bool    operator!=(const Fixed &other) const;
	bool    operator==(const Fixed &other) const;
	
	Fixed   operator+(const Fixed &other) const;
	Fixed   operator-(const Fixed &other) const;
	Fixed   operator*(const Fixed &other) const;
	Fixed   operator/(const Fixed &other) const;

 	Fixed&  operator++(void); 				// ++i
	Fixed 	operator++(int);  				// i++;
	Fixed&  operator--(void); 				// --i
	Fixed 	operator--(int);  				// i--;

	static Fixed& min(Fixed &num1, Fixed &num2);
	static const Fixed& min(const Fixed &num1, const Fixed &num2);
	static Fixed& max(Fixed &num1, Fixed &num2);
	static const Fixed& max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream &stream, Fixed const &num);

#endif