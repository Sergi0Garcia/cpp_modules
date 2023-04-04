/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:38:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:56 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"

Zombie::Zombie(std::string name) :_name(name)
{
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