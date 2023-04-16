/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:34:43 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 20:56:37 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
public:
  Character(void);
  Character(const Character &other);
  Character &operator=(const Character &other);
  ~Character(void);

private:
  std::string _name;
  AMateria *_inventory[4];
};
#endif