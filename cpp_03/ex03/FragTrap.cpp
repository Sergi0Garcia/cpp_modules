/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:27:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 13:28:06 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "Colors.hpp"

FragTrap::FragTrap(void) :ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << GREEN;
    std::cout << "[FRAGTRAP]: ";
    std::cout << this->_name << " (default) constructor called" << std::endl;
    std::cout << RESET;
}

FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << GREEN;
    std::cout << "[FRAGTRAP]: ";
    std::cout << this->_name << " constructor called" << std::endl;
    std::cout << RESET;
}

FragTrap::~FragTrap(void)
{
    std::cout << RED;
    std::cout << "[FRAGTRAP]: ";
    std::cout << this->_name << " destructor called" << std::endl;
    std::cout << RESET;
    return ;
}

FragTrap::FragTrap(const FragTrap& other)
{
    *this = other;
    std::cout << YELLOW;
    std::cout << "[FRAGTRAP]: ";
    std::cout << "Copy constructor called" << std::endl;
    std::cout << RESET;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

bool FragTrap::validAction(void) const
{
    if (this->_hitPoints <= 0 ){
        std::cout << "[FRAGTRAP]: ";
        std::cout << this->_name << " has no hit points" << std::endl;
        return (false);
    }
    else if (this->_energyPoints <= 0){
        std::cout << "[FRAGTRAP]: ";
        std::cout << this->_name << " has no energy points" << std::endl;
        return (false);
    }
    return (true);
}

void FragTrap::highFivesGuys(void)
{
    if (!this->validAction())
        return;
    std::cout << "[FRAGTRAP]: " << this->_name;
    std::cout << " High fives for everyone 👋!" << std::endl;
    this->_energyPoints -= 1;
}