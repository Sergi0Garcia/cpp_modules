/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:26:38 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 14:21:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
    std::string _name;
public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif