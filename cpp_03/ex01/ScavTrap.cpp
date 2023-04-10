/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:27:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 11:03:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "Colors.hpp"

ScavTrap::ScavTrap(void) :ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN;
    std::cout << "[SCAVTRAP]: ";
    std::cout << this->_name << " (default) constructor called" << std::endl;
    std::cout << RESET;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN;
    std::cout << "[SCAVTRAP]: ";
    std::cout << this->_name << " constructor called" << std::endl;
    std::cout << RESET;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << RED;
    std::cout << "[SCAVTRAP]: ";
    std::cout << this->_name << " destructor called" << std::endl;
    std::cout << RESET;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    *this = other;
    std::cout << YELLOW;
    std::cout << "[SCAVTRAP]: ";
    std::cout << "Copy constructor called" << std::endl;
    std::cout << RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    if (!this->validAction())
        return;
    std::cout << PURPLE;
    std::cout << "[SCAVTRAP]: ";
    std::cout << this->_name << " is now in Gate keeper mode!" << std::endl;
    std::cout << RESET;
    this->_energyPoints -= 1;
    return ;
}

bool ScavTrap::validAction(void) const
{
    if (this->_hitPoints <= 0 ){
        std::cout << "[SCAVTRAP]: ";
        std::cout << this->_name << " has no hit points" << std::endl;
        return (false);
    }
    else if (this->_energyPoints <= 0){
        std::cout << "[SCAVTRAP]: ";
        std::cout << this->_name << " has no hit energy points" << std::endl;
        return (false);
    }
    return (true);
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->validAction())
        return;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
    return ;
}