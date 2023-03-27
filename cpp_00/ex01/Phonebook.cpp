/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:03:59 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 13:35:44 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <cstdlib>

Phonebook::Phonebook(void)
{
    return ;
}

Phonebook::~Phonebook(void)
{
    return ;
}

void Phonebook::init_prompt(void)
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Enter command: ADD, EXIT, SEARCH" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

 int Phonebook::_available_idx(void)
 {
    int i = 0;
    while (i < 7 && this->_contacts[i].valid())
        i++;
    return (i);
 }

int Phonebook::_input(std::string str)
{
    std::string input;
    std::cout << str;
    std::getline(std::cin, input);
    while (!std::cin.good() || input.empty() 
           || (std::atoi(str.c_str()) < 0 || std::atoi(str.c_str()) > 8))
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin.clear();
        std::getline(std::cin, input);
    }
    return (std::atoi(input.c_str()));
}

void Phonebook::add_contact()
{
    int idx = this->_available_idx();
    this->_contacts[idx].add();
    return ;
}

void Phonebook::display_contacts(void)
{
    int i = 0;
    while (i < 8)
    {
        this->_contacts[i].short_view(i);
        i++;
    }
}

void Phonebook::view_full_info(void)
{
    int idx = this->_input("Enter user index: ");
    this->_contacts[idx].large_view();
}