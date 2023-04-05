/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:09:29 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 12:18:24 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"
#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4){
        std::cout << RED << "Usage: <Filename> <s1> <s2>" << RESET << std::endl;
        return (EXIT_FAILURE);
    }
    Sed sedController(argv[1], argv[2], argv[3]);
    if (!sedController.isValid()){
        std::cout << RED << "Error: input has an empty string" << RESET << std::endl;
        return (EXIT_FAILURE);
    }
    bool execution;
    execution = sedController.execute();
    return (execution);
}