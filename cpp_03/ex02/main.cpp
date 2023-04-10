/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 13:15:18 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    FragTrap frag("Frog");
    FragTrap def;
    FragTrap copy(def);

    frag.highFivesGuys();
    frag.showStatus();
    frag.takeDamage(500);
    
    frag.highFivesGuys();
    def.highFivesGuys();

    // system("leaks ex02");
    return (0);
}
