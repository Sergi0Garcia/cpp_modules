/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 15:06:54 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Colors.hpp"
#include <iomanip>

void    title(std::string str)
{
    std::cout << PURPLE;
    std::cout << "----------------" << std::endl;
    std::cout <<  std::setw((16 + str.length()) / 2) << str << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << RESET;
    return ;
}

int init_test(void)
{
    title("initial_tests");
    
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return (0);
}

int comparison_test(void)
{
    Fixed const a(5);
    Fixed const b(5);
    Fixed const c(10);
    Fixed const d(15);

    title("comparison_test");
    // operator>
    if (a > c)
        std::cout << "a is greater than c" << std::endl;
    else
        std::cout << "c is greater than a" << std::endl;
        
    // operator<
    if (c < b)
         std::cout << "c is smaller than b" << std::endl;
    else 
        std::cout << "b is smaller than c" << std::endl;

    // operator>=
    if (a >= b)
        std::cout << "a is grater than or equal than b" << std::endl;
    else
        std::cout << "b is grater than a" << std::endl; 

    // operator<=
    if (d <= c)
        std::cout << "d is less than or equal to c" << std::endl;
    else 
        std::cout << "c is less than d" << std::endl;

    // operator!=
    if (a != c)
        std::cout << "a is different than c" << std::endl;
    else
        std::cout << "a is equal than c" << std::endl;
    
    // operator==
    if (a == b)
        std::cout << "a is equal to b" << std::endl;
    else
        std::cout << "a and b are not equal" << std::endl;
    return (0);
}

int operator_test(void)
{
    title("operator_test");
    Fixed const a(5);
    Fixed const b(10);
    Fixed const c(15);
    Fixed const d(20);

    Fixed sum;
    Fixed sub;
    Fixed div;
    Fixed mult;

    sum = a + b;
    std::cout << "a + b = " << sum << std::endl;
    sub = a - b;
    std::cout << "a - b = " << sub << std::endl;
    div = d / a;
    std::cout << "d / a = " << div << std::endl;
    mult = b * c;
    std::cout << "b * c = " << mult << std::endl;
    return (0);
}

int main(void) 
{
    init_test();
    // comparison_test();
    // operator_test();
    // system("leaks ex02");
    return (0);
}