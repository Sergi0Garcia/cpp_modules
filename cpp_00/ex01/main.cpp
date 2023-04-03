/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:42:47 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/03 12:53:13 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string command;

    book.init_prompt();
    std::cout << "- " ;
    std::getline(std::cin, command);
    while (command.compare("EXIT") != 0)
    {
        if (command.compare("ADD") == 0)
            book.add_contact();
        if (command.compare("SEARCH") == 0)
        {
            if (book.display_contacts() == EXIT_SUCCESS)
                book.view_full_info();
        }
        std::cout << "- " ;
        std::getline(std::cin, command);
    }
    return (EXIT_SUCCESS);
}
