/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:01:57 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 13:19:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Colors.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN;
    std::cout << "[CLAPTRAP]: ";
    std::cout << this->_name << " constructor called" << std::endl;
    std::cout << RESET;
    return ;
}

ClapTrap::ClapTrap(void): _name("defaultName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN;
    std::cout << "[CLAPTRAP]: ";
    std::cout << this->_name << " (default) constructor called" << std::endl;
    std::cout << RESET;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << RED;
    std::cout << "[CLAPTRAP]: ";
    std::cout << this->_name << " destructor called" << std::endl;
    std::cout << RESET;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << YELLOW;
    std::cout << "[CLAPTRAP]: ";
    std::cout << "Copy constructor called" << std::endl;
    std::cout << RESET;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

bool ClapTrap::validAction(void) const
{
    if (this->_hitPoints <= 0 ){
        std::cout << this->_name << " has no hit points" << std::endl;
        return (false);
    }
    else if (this->_energyPoints <= 0){
        std::cout << this->_name << " has no energy points" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::showStatus(void) const
{
    std::cout << BLUE;
    std::cout << "--------------------" << std::endl;
    std::cout << "[CLAPTRAP]: ";
    std::cout << this->_name << " INFO" << std::endl;
    std::cout << "Hit Points: " << this->_hitPoints << std::endl;
    std::cout << "Energy Points: " << this->_energyPoints << std::endl;
    std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << RESET;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->validAction())
        return;
    std::cout << "[CLAPTRAP] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0){
        std::cout << "[CLAPTRAP] " << this->_name << " is already dead :(" << std::endl;
        return ;
    }
    std::cout << "[CLAPTRAP] " << this->_name << " takes " << amount << " damage!" << std::endl;
    if (amount >= this->_hitPoints){
        std::cout << "[CLAPTRAP] " << this->_name << " died :(" << std::endl;
        this->_hitPoints = 0;
        return ;
    }
    this->_hitPoints -= amount;
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->validAction())
        return;
    std::cout << "[CLAPTRAP] " << this->_name << " repairs with " << amount << " hit points!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    return ;
}
