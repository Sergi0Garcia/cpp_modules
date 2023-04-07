/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/07 17:45:23 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Colors.hpp"
#include "Point.hpp"

// Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
// Output: Inside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /   P   \      P
//             /         \
//      A(0,0) ----------- C(20,0) 
// 
// Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
// Output: Outside
// Explanation:
//               B(10,30)
//                 / \
//                /   \
//               /     \
//              /       \      P
//             /         \
//      A(0,0) ----------- C(20,0) 

int main(void) 
{
    Point const a(0.0, 0.0);
    Point const b(10.0, 30.0);
    Point const c(20.0, 0.0);
    Point const p(30.0, 15.0);

    if (bsp(a, b, c, p) == true) 
    {
        std::cout << "Point is inside" << std::endl;
    } 
    else 
    {
        std::cout << "Point is outside" << std::endl;
    }
    return (0);
}