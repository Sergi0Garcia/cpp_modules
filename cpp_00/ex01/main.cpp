/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:47 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 13:34:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string command;

    phonebook.init_prompt();
    std::getline(std::cin, command);
    while (command.compare("EXIT") != 0)
    {
        std::cout << "Command: " << command << std::endl;
        if (command.compare("ADD") == 0)
            phonebook.add_contact();
        if (command.compare("SEARCH") == 0)
        {
            phonebook.display_contacts();
            phonebook.view_full_info();
        }
        std::getline(std::cin, command);
    }
    return (EXIT_SUCCESS);
}