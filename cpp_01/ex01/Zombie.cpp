/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:38:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 11:44:24 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie initialized" << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << RED;
    std::cout << this->_name << " destroyed" << std::endl;
    std::cout << RESET;
    return ;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
    return ;
}
