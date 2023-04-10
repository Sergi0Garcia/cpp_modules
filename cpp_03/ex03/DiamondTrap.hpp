/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:22:04 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 12:13:53 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * To prevent the new class from having two instances of the parent class, you can use virtual inheritance. 
 * Virtual inheritance is a technique in C++ that allows a derived class to inherit from a base class only once,
 * even if the base class is inherited by multiple paths in the inheritance hierarchy
 */

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap(void);
    DiamondTrap(std::string name); 
    ~DiamondTrap(void);
    // DiamondTrap(const DiamondTrap& other);
    // DiamondTrap& operator=(const DiamondTrap& other);
    using ScavTrap::attack;
    void whoAmI(void);
};

#endif