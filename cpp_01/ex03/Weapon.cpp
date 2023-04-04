/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:31:29 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 13:06:35 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type): _type(type)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string& Weapon::getType(void) const
{
    return (this->_type);
}

void Weapon::setType(std::string newType)
{
    this->_type = newType;
    return ;
}
