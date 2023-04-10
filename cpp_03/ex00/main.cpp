/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 13:01:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap john("John");
    ClapTrap dave("Dave");
    ClapTrap smith("Smith");
    ClapTrap def;
    ClapTrap clone(smith);

    for (int i = 0; i < 11; i++)
        john.attack("Dave");

    dave.showStatus();
    john.showStatus();

    john.beRepaired(10);

    clone.takeDamage(15);
    clone.takeDamage(100);
    clone.beRepaired(100);
    clone.attack("John");
    clone.showStatus();
    
    dave.beRepaired(100);
    dave.showStatus();
    
    // system("leaks ex00");
    
    return (0);
}