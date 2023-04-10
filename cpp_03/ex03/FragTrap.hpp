/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:27:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/10 12:50:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private: 
    bool validAction(void) const;
public:
    FragTrap(void);
    FragTrap(std::string name); 
    ~FragTrap(void);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    void highFivesGuys(void);
};

#endif