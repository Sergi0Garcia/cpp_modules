/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:39:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 09:51:26 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * the copy constructor creates a new object by copying the values of other into the newly created object. 
 * The copy assignment operator overload, on the other hand, copies the values of other into the existing object pointed to by this. 
*/
#include <iostream>
class Fixed {
private:
	int					_fixedPointNumber;
	static const int	_fractionalBits = 8; 
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other); // copy constructor
	Fixed& operator=(const Fixed& other); // copy assignment operator overload
	~Fixed(void);
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int   	toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &num);