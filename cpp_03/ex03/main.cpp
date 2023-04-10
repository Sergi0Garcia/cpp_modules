/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 12:40:22 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
int main(void)
{
    DiamondTrap diamond("Diamond");
    DiamondTrap copy(diamond);

    
    diamond.showStatus();
    copy.showStatus();

    diamond.whoAmI();
    diamond.attack("stranger");
    // system("leaks ex03");
    return (0);
}
