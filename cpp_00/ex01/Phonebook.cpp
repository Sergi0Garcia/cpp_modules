/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:03:59 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/03 11:17:24 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Colors.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << RED << "PhoneBook destroyed" << DEFAULT << std::endl;
    return ;
}

void PhoneBook::init_prompt(void)
{
    std::cout << GREEN << "--------------------------------" << std::endl;
    std::cout << "Enter command: ADD, EXIT, SEARCH" << std::endl;
    std::cout << "--------------------------------" << DEFAULT << std::endl;
}

 int PhoneBook::_available_idx(void)
 {
    int i = 0;
    while (i < 7 && this->_contacts[i].valid())
        i++;
    return (i);
 }

int PhoneBook::_input(std::string str)
{
    std::string input;
    std::cout << str;
    std::getline(std::cin, input);
    while (!std::cin.good() 
          || input.empty() 
          || (std::atoi(input.c_str()) < 0 || std::atoi(input.c_str()) > 7)
          || (std::atoi(input.c_str()) == 0 && input.compare("0")) 
          || (std::atoi(input.c_str()) < 7 && std::atoi(input.c_str()) >= this->_available_idx())
          || (std::atoi(input.c_str()) == 7 && !this->_contacts[7].valid()))
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin.clear();
        std::getline(std::cin, input);
    }
    return (std::atoi(input.c_str()));
}

void PhoneBook::add_contact()
{
    int idx = this->_available_idx();
    this->_contacts[idx].add();
    return ;
}

int PhoneBook::display_contacts(void)
{
    int i = 0;
    while (i < 8)
    {
        if (this->_contacts[i].short_view(i) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

void PhoneBook::view_full_info(void)
{
    int idx = this->_input("Enter user index: ");
    this->_contacts[idx].large_view();
}