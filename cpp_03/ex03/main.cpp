/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 13:38:30 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Diamond");
    DiamondTrap def;
    DiamondTrap copy(def);

    diamond.showStatus();
    copy.showStatus();

    diamond.whoAmI();
    def.whoAmI();
    copy.whoAmI();

    diamond.attack("copy");
    copy.takeDamage(30);
    copy.takeDamage(500);
    copy.showStatus();
    copy.highFivesGuys();
    diamond.highFivesGuys();

    // system("leaks ex03");
    return (0);
}
