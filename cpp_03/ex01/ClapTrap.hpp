/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:58:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 10:45:03 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
protected:
    std::string     _name;
    unsigned int    _hitPoints;                       // represents Health
    unsigned int    _energyPoints;
    unsigned int    _attackDamage;
    bool validAction(void) const;
public:
    ClapTrap(std::string name);                       // constructor
    ClapTrap(void);                                   // default constructor
    ~ClapTrap(void);                                  // destructor
    ClapTrap(const ClapTrap& other);                  // copy constructor
    ClapTrap& operator=(const ClapTrap& other);       // copy assignemt operator overload
    void showStatus(void) const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif