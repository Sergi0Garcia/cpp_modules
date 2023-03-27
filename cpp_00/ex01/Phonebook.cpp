/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:03:59 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 12:38:09 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

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

void Phonebook::add_contact()
{
    int idx = this->_available_idx();
    this->_contacts[idx].add();
    return ;
}

 int Phonebook::_available_idx(void)
 {
    int i = 0;
    while (i < 7 && this->_contacts[i].valid())
        i++;
    return (i);
 }