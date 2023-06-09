/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/15 21:13:42 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap clap("John");
  ScavTrap scav("Robot");
  ScavTrap def;
  ScavTrap copy(def);

  clap.attack("Robot");
  scav.attack("John");
  clap.takeDamage(20);

  clap.showStatus();
  scav.showStatus();

  scav.guardGate();
  scav.guardGate();

  scav.takeDamage(200);

  scav.guardGate();
  scav.attack("def");

  scav.showStatus();
  // system("leaks ex01");
  return (0);
}
