/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:15 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 11:57:44 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;
    
    std::cout << PURPLE;
    std::cout << "Address" << RESET << std::endl;
    std::cout << &str << std::endl;
    std::cout << strPTR << std::endl;
    std::cout << &strREF << std::endl;

    std::cout << PURPLE;
    std::cout << "Value " << RESET << std::endl;
    std::cout << str << std::endl;
    std::cout << *strPTR << std::endl;
    std::cout << strREF << std::endl;
    
    return (EXIT_SUCCESS);
}