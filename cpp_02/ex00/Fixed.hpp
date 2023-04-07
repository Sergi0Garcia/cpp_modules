/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:39:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 09:19:28 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The copy constructor creates a new object by copying the values of other into the newly created object. 
 * The copy assignment operator overload copies the values of other into the existing object pointed to by this. 
*/
class Fixed {
private:
	int					_fixedPointNumber;
	static const int	_fractionalBits = 8; 
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& other); // copy constructor
	Fixed& operator=(const Fixed& other); // copy assignment operator overload
	int getRawBits(void) const;
	void setRawBits(int const raw);
};