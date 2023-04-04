/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:30:11 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 13:10:46 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon(void);
    void setType(std::string newtype);
    const std::string&  getType(void) const;
};

#endif