/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:26:38 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 11:44:04 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
    std::string _name;
public:
    Zombie(void);
    ~Zombie(void);
    void setName(std::string name);
    void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif