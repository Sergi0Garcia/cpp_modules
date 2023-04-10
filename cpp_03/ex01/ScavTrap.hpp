/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:27:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 10:14:28 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private: 
    bool validAction(void) const;
public:
    ScavTrap(void);
    ScavTrap(std::string name); 
    ~ScavTrap(void);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);

    void guardGate(void);
    void attack(const std::string& target);
};

#endif