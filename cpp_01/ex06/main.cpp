/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:17:29 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 12:51:28 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "usage: ./harlFilter <FILTER>" << RESET << std::endl;
        return (EXIT_FAILURE);
    }       
    Harl harl;
    harl.complain(argv[1]);
    // system("leaks harlFilter");
    return (EXIT_SUCCESS);
}