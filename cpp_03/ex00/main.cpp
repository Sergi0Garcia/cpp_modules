/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 10:43:36 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap john("John");
    ClapTrap dave("Dave");
    ClapTrap smith("Smith");
    ClapTrap clone(smith);
    ClapTrap def;

    for (int i = 0; i < 10; i++)
        john.attack("Dave");

    dave.showStatus();
    john.showStatus();

    john.beRepaired(10);
    clone.takeDamage(15);
    clone.takeDamage(100);
    clone.showStatus();
    dave.beRepaired(100);
    dave.showStatus();
    
    return (0);
}