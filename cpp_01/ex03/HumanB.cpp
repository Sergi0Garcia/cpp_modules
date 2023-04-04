/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:46:19 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 13:10:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) :_name(name)
{
    this->_weapon = NULL;
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
    return ;
}

void HumanB::attack(void) const
{
    if (this->_weapon != NULL)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon" << std::endl;
    return ;
}