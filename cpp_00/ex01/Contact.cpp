/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:08 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 12:47:42 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "Colors.hpp"

Contact::Contact(void)
{
    std::cout << "Constructur called" << std::endl;
    return ;
}

Contact::~Contact(void)
{
    std::cout << "Destructur called" << std::endl;
    std::cout << this->_first_name << std::endl;
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
    std::cout << GREEN << "User saved correctly" << DEFAULT << std::endl;
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