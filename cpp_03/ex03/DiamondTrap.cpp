/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/14 16:11:38 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "Colors.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name) {
  this->_name = name;
  this->ClapTrap::_name = name + "_clap_name";
  this->FragTrap::_hitPoints = 100;
  this->ScavTrap::_energyPoints = 50;
  this->FragTrap::_attackDamage = 30;
  std::cout << GREEN;
  std::cout << "[DIAMODNTRAP]: ";
  std::cout << this->_name << " constructor called" << std::endl;
  std::cout << RESET;
  return;
}

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() {
  this->_name = "DefaultDiamond";
  this->ClapTrap::_name = "DefaultDiamond_clap_name";
  this->FragTrap::_hitPoints = 100;
  this->ScavTrap::_energyPoints = 50;
  this->FragTrap::_attackDamage = 30;
  std::cout << GREEN;
  std::cout << "[DIAMODNTRAP]: ";
  std::cout << this->_name << " (default) constructor called" << std::endl;
  std::cout << RESET;
  return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[DIAMODNTRAP]: ";
  std::cout << "Copy constructor called" << std::endl;
  std::cout << RESET;
  return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  ClapTrap::operator=(other);
  this->_name = other._name;
  return (*this);
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << RED;
  std::cout << "[DIAMODNTRAP]: ";
  std::cout << this->_name << " destructor called" << std::endl;
  std::cout << RESET;
  return;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap name: " << this->_name
            << ", ClapTrap name: " << ClapTrap::_name << std::endl;
  return;
}