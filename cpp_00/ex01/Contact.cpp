/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:08 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/03 11:16:36 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "Colors.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

std::string Contact::_input(std::string str)
{
    std::string input;
    std::cout << str;
    std::getline(std::cin, input);
    while (!std::cin.good() || input.empty())
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin.clear();
        std::getline(std::cin, input);
    }
    return (input);
}

void Contact::add(void)
{
    this->_first_name = this->_input("First name: ");
    this->_last_name = this->_input("Last name: ");
    this->_nickname = this->_input("Nickname: ");
    this->_phone_number = this->_input("Phone number: ");
    this->_darkest_secret = this->_input("Darkest secret: ");
    std::cout << GREEN << "User saved correctly" << std::endl;
    std::cout << DEFAULT << std::endl;
    return ;
}

bool Contact::valid(void)
{
    if (!this->_first_name.empty() &&
        !this->_last_name.empty() && 
        !this->_nickname.empty() &&
        !this->_phone_number.empty() && 
        !this->_darkest_secret.empty())
        return (true);
    return (false);
}

std::string Contact::_trim(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

 int    Contact::short_view(int idx)
 {
    if (idx == 0 && !this->valid())
    {
        std::cout << RED << "No users found" << DEFAULT << std::endl;
        return (EXIT_FAILURE);
    }
    if (!this->valid())
        return (EXIT_SUCCESS);
    std::cout << BLUE << "|" << std::setw(10) << idx;
    std::cout << "|" << std::setw(10) << this->_trim(this->_first_name) << std::flush;
    std::cout << "|" << std::setw(10) << this->_trim(this->_last_name) << std::flush;
    std::cout << "|" << std::setw(10) << this->_trim(this->_nickname) << std::flush;
    std::cout << "|" << DEFAULT << std::endl;
    return (EXIT_SUCCESS);
}

void    Contact::large_view(void)
{
    if (!this->valid())
        return ;
    std::cout << BLUE;
    std::cout << "First name: " << this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret  << std::endl;
    std::cout << DEFAULT << std::endl;
}